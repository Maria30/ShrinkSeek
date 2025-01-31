// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShrinkSeekEditorTarget : TargetRules
{
	public ShrinkSeekEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		bUseUnityBuild = false; // Désactivation

		bOverrideBuildEnvironment = true;

		ExtraModuleNames.AddRange( new string[] { "ShrinkSeek" } );
	}
}
