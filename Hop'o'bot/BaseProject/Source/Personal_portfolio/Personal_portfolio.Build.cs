// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Personal_portfolio : ModuleRules
{
	public Personal_portfolio(ReadOnlyTargetRules Target) : base(Target)
	{


        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        // Stub out Clang-only __has_feature macro for MSVC builds
        PublicDefinitions.Add("__has_feature(x)=0");
    }
}
