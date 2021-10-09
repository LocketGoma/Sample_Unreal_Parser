// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TestProjectEditorTarget : TargetRules
{
	public TestProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("TestProject");
		ExtraModuleNames.Add("JsonParser");
		ExtraModuleNames.Add("ProceduralMapGenerator");
	}
}
