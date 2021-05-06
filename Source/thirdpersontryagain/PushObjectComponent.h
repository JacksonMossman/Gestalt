// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "PushObjectComponent.generated.h"


UCLASS( ClassGroup=(PushObject), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONTRYAGAIN_API UPushObjectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPushObjectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	APlayerController* PlayerController;

	AActor* ParentActor;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RayCastDistance = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RailedPushForce = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float UnRailedPushForce = 0;
};
