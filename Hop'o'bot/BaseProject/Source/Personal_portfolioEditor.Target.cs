// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Personal_portfolioEditorTarget : TargetRules
{
	public Personal_portfolioEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		//ExtraModuleNames.AddRange( new string[]{"Personal_portfolio", "Personal_portfolioEditor"});
		ExtraModuleNames.Add("Personal_portfolio");
		ExtraModuleNames.Add("Personal_portfolioEditor");
	}
}
