// Fill out your copyright notice in the Description page of Project Settings.


#include "ParkorMathFunctions.h"


float UParkorMathFunctions::CameraXRotationManager(float X)
{
	if (X >= 360)
	{
		return X - 360;
	}
	else if (X <= 0)
	{
		return X + 360;
	}
	else
	{
		return X;
	}
}



