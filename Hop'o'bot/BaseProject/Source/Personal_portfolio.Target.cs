// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Personal_portfolioTarget : TargetRules
{
	public Personal_portfolioTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		//ExtraModuleNames.AddRange( new string[]{"Personal_portfolio", "Personal_portfolioEditor"});
		ExtraModuleNames.Add("Personal_portfolio");
		//ExtraModuleNames.Add("Personal_portfolioEditor");
	}
}
