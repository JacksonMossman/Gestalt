// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ParkorMathFunctions.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONTRYAGAIN_API UParkorMathFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
		float CameraXRotationManager(float X);

};
