// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class thirdpersontryagainTarget : TargetRules
{
	public thirdpersontryagainTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "thirdpersontryagain" } );
	}
}
