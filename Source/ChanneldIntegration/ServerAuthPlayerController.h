#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ServerAuthPlayerController.generated.h"

/**
 *
 */
UCLASS()
class CHANNELDINTEGRATION_API AServerAuthPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void  GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;
	// Channeld Connection Id, Only valid on server
	UPROPERTY(BlueprintReadOnly)
		int32 ChanneldConnId;

	UPROPERTY(BlueprintReadOnly, Replicated)
		FString PlayerAlias;
};
