#include "ChanneldReplicationComponent.h"
#include "ChanneldGameInstanceSubsystem.h"
#include "ChannelDataProvider.h"
#include "View/ChannelDataView.h"
#include "Engine/ActorChannel.h"
#include "Engine/PackageMapClient.h"
#include "Misc/NetworkGuid.h"
#include "ChanneldReplication.h"
#include "ChanneldNetDriver.h"
#include "ChanneldSettings.h"

UChanneldReplicationComponent::UChanneldReplicationComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
}

const google::protobuf::Message* UChanneldReplicationComponent::GetStateFromChannelData(google::protobuf::Message* ChannelData, UObject* TargetObject, uint32 NetGUID, bool& bIsRemoved)
{
	bIsRemoved = false;
	return nullptr;
}

void UChanneldReplicationComponent::SetStateToChannelData(const google::protobuf::Message* State, google::protobuf::Message* ChannelData, UObject* TargetObject, uint32 NetGUID)
{

}

void UChanneldReplicationComponent::PostInitProperties()
{
	Super::PostInitProperties();

	InitOnce();
}

void UChanneldReplicationComponent::InitOnce()
{
	if (!GetOwner())
		return;

	if (bInitialized)
		return;

	auto Settings = GetMutableDefault<UChanneldSettings>();
	if (Settings->bSkipCustomReplication && Settings->bSkipCustomRPC)
	{
		return;
	}

	// TODO: OwnerOnly replication should use private channels
	if (GetOwner()->GetIsReplicated() || GetOwner()->bOnlyRelevantToOwner)
	{
		auto OwnerReplicators = ChanneldReplication::FindAndCreateReplicators(GetOwner());
		if (OwnerReplicators.Num() > 0)
		{
			Replicators.Append(OwnerReplicators);
		}
		else
		{
			UE_LOG(LogChanneld, Warning, TEXT("Unable to add replicator for owner actor: %s"), *GetOwner()->GetFullName());
		}
	}
	for (auto RepComp : GetOwner()->GetReplicatedComponents())
	{
		auto CompReplicators = ChanneldReplication::FindAndCreateReplicators(RepComp);
		if (CompReplicators.Num() > 0)
		{
			Replicators.Append(CompReplicators);
		}
		else
		{
			UE_LOG(LogChanneld, Warning, TEXT("Unable to add replicator for component '%s' of actor: %s"), *RepComp->GetFullName(), *GetOwner()->GetFullName());
		}
	}

	bInitialized = true;
}

void UChanneldReplicationComponent::BeginPlay()
{
	Super::BeginPlay();

	InitOnce();

	UChannelDataView* View = GetOwner()->GetGameInstance()->GetSubsystem<UChanneldGameInstanceSubsystem>()->GetChannelDataView();
	if (View)
	{
		View->AddProvider(OwningChannelId, this);
	}
}

void UChanneldReplicationComponent::EndPlay(EEndPlayReason::Type Reason)
{
	Super::EndPlay(Reason);

	//if (Reason != EEndPlayReason::LevelTransition)
	{
		UChannelDataView* View = GetOwner()->GetGameInstance()->GetSubsystem<UChanneldGameInstanceSubsystem>()->GetChannelDataView();
		if (View)
		{
			View->RemoveProviderFromAllChannels(this, true);
		}
	}
}

// Called every frame
void UChanneldReplicationComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TODO: update the replicators with the dynamically added/removed components

	/*
	for (auto Pair : SceneComponentReplicators)
	{
		Pair.Value->Tick(DeltaTime);
	}
	*/
}

channeldpb::ChannelType UChanneldReplicationComponent::GetChannelType()
{
	return static_cast<channeldpb::ChannelType>(ChannelType);
}

google::protobuf::Message* UChanneldReplicationComponent::GetChannelDataTemplate() const
{
	auto MsgObj = ProvideChannelDataTemplate();
	if (MsgObj)
	{
		return MsgObj->GetMessage();
	}
	else
	{
		UE_LOG(LogChanneld, Error, TEXT("ChanneldActor '%s' failed to provider channel data template"), *GetFName().ToString());
		return nullptr;
	}
}

ChannelId UChanneldReplicationComponent::GetChannelId()
{
	return OwningChannelId;
}

void UChanneldReplicationComponent::SetChannelId(ChannelId ChId)
{
	OwningChannelId = ChId;
}

bool UChanneldReplicationComponent::IsRemoved()
{
	return bRemoved;
}

void UChanneldReplicationComponent::SetRemoved()
{
	bRemoved = true;
}

bool UChanneldReplicationComponent::UpdateChannelData(google::protobuf::Message* ChannelData)
{
	if (!GetOwner()->HasAuthority())
	{
		return false;
	}

	bool bUpdated = false;
	for (auto Replicator : Replicators)
	{
		Replicator->Tick(FApp::GetDeltaTime());
		if (Replicator->IsStateChanged())
		{
			uint32 NetGUID = Replicator->GetNetGUID();
			if (NetGUID == 0)
			{
				UE_LOG(LogChanneld, Log, TEXT("Replicator of %s doesn't has a NetGUID yet, skip setting channel data"), *Replicator->GetTargetObject()->GetName());
				continue;
			}
			SetStateToChannelData(Replicator->GetDeltaState(), ChannelData, Replicator->GetTargetObject(), NetGUID);
			Replicator->ClearState();
			bUpdated = true;
		}
	}

	return bUpdated;
}

void UChanneldReplicationComponent::OnChannelDataUpdated(google::protobuf::Message* ChannelData)
{
	// FIXME: don't update if the source (the connection that updated the channel data) is self.

	for (auto Replicator : Replicators)
	{
		auto TargetObj = Replicator->GetTargetObject();
		if (!TargetObj)
		{
			UE_LOG(LogChanneld, Warning, TEXT("Replicator's target object is missing (maybe already destroyed)"));
			continue;
		}
		uint32 NetGUID = Replicator->GetNetGUID();
		if (NetGUID == 0)
		{
			// TODO: delay the state update
			UE_LOG(LogChanneld, Warning, TEXT("Replicator of %s doesn't have a valid NetGUID (maybe the NetDriver is not initialized yet) to find the state."), *Replicator->GetTargetObject()->GetName());
			continue;
		}
		bool bIsRemoved = false;
		auto State = GetStateFromChannelData(ChannelData, Replicator->GetTargetObject(), NetGUID, bIsRemoved);
		if (State)
		{
			if (bIsRemoved)
			{
				if (TargetObj == GetOwner())
				{
					GetOwner()->Destroy(true);
				}
				else if (TargetObj->IsA<UActorComponent>())
				{
					GetOwner()->RemoveOwnedComponent(Cast<UActorComponent>(TargetObj));
				}
				continue;
			}
			Replicator->OnStateChanged(State);
		}
	}
}

TSharedPtr<google::protobuf::Message> UChanneldReplicationComponent::SerializeFunctionParams(AActor* Actor, UFunction* Func, void* Params, bool& bSuccess)
{
	for (auto Replicator : Replicators)
	{
		if (Replicator->GetTargetObject() == Actor)
		{
			auto ParamsMsg = Replicator->SerializeFunctionParams(Func, Params, bSuccess);
			if (bSuccess)
			{
				return ParamsMsg;
			}
		}
	}

	bSuccess = false;
	return nullptr;
}

void* UChanneldReplicationComponent::DeserializeFunctionParams(AActor* Actor, UFunction* Func, const std::string& ParamsPayload, bool& bSuccess, bool& bDelayRPC)
{
	for (auto Replicator : Replicators)
	{
		if (Replicator->GetTargetObject() == Actor)
		{
			void* Params = Replicator->DeserializeFunctionParams(Func, ParamsPayload, bSuccess, bDelayRPC);
			if (bSuccess)
			{
				return Params;
			}
		}
	}

	bSuccess = false;
	return nullptr;
}
