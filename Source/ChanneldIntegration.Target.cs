using UnrealBuildTool;
using System.Collections.Generic;

public class ChanneldIntegrationTarget : TargetRules
{
	public ChanneldIntegrationTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "ChanneldIntegration" } );
	}
}
