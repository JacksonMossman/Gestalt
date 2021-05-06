// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "StaminaComponent.generated.h"


UCLASS(ClassGroup = (Stamina), meta = (BlueprintSpawnableComponent))
class THIRDPERSONTRYAGAIN_API UStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UStaminaComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxStamina = 0;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseDelay = 0;
	float StaminaDelay = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float StaminaRate = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DrainStamina;

	UCharacterMovementComponent* CharacterMovement;
	UMaterialInstanceDynamic* WingMaterial;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void DecreaseStamina(float DecreaseAmount, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		void IncreaseStamina(float IncreaseAmount, float DeltaTime);
	UFUNCTION(BlueprintCallable)
		void IncreaseMaxStamina(float IncreaseAmount);
	UFUNCTION(BlueprintCallable)
		void StartStaminaRegen();
	UFUNCTION(BlueprintCallable)
		void StopStaminaRegen();
	UFUNCTION(BlueprintCallable)
		void RestartDelayTimer();
};
