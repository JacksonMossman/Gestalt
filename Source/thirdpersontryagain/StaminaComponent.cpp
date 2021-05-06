// Fill out your copyright notice in the Description page of Project Settings.


#include "StaminaComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/MeshComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UStaminaComponent::UStaminaComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStaminaComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Stamina = MaxStamina;
	StaminaDelay = BaseDelay;
	CharacterMovement = Cast<UCharacterMovementComponent>(GetOwner()->GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	UMeshComponent* PlayerMesh = Cast<UMeshComponent>(GetOwner()->GetComponentByClass(UMeshComponent::StaticClass()));
	WingMaterial = UMaterialInstanceDynamic::Create(PlayerMesh->GetMaterial(1), nullptr);
	WingMaterial->SetScalarParameterValue(FName(TEXT("CurrentStamina")), Stamina / MaxStamina);
	PlayerMesh->SetMaterial(1, WingMaterial);
}

// Called every frame
void UStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	StaminaDelay -= DeltaTime;

	if (CharacterMovement->IsFalling())
		RestartDelayTimer();

	if (StaminaDelay <= 0 && BaseDelay > 0)
		DrainStamina = false;

	if (!DrainStamina) {

		StaminaDelay = 0;

		if (Stamina <= MaxStamina)
			Stamina += (StaminaRate * DeltaTime);

		if (Stamina > MaxStamina)
			Stamina = MaxStamina;
	}
	WingMaterial->SetScalarParameterValue(FName(TEXT("CurrentStamina")), Stamina / MaxStamina);
}

void UStaminaComponent::DecreaseStamina(float DecreaseAmount, float DeltaTime)
{
	Stamina -= DecreaseAmount * DeltaTime;
	DrainStamina = true;
	RestartDelayTimer();
}

void UStaminaComponent::IncreaseStamina(float IncreaseAmount, float DeltaTime)
{
	Stamina += IncreaseAmount * DeltaTime;
}

void UStaminaComponent::IncreaseMaxStamina(float IncreaseAmount)
{
	MaxStamina += IncreaseAmount;
}

void UStaminaComponent::StartStaminaRegen()
{
	DrainStamina = false;
}

void UStaminaComponent::StopStaminaRegen()
{
	DrainStamina = true;
}

void UStaminaComponent::RestartDelayTimer()
{
	StaminaDelay = BaseDelay;
	DrainStamina = true;
}

