// Fill out your copyright notice in the Description page of Project Settings.


#include "PushObjectComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PushableObjectComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UPushObjectComponent::UPushObjectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPushObjectComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	ParentActor = GetOwner();
}


// Called every frame
void UPushObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (PlayerController->IsInputKeyDown("F")) {
		
		FVector Start = ParentActor->GetActorLocation();
		FVector ForwardVector = ParentActor->GetActorForwardVector();
		FVector End = (ForwardVector * RayCastDistance) + Start;
		FHitResult HitResult;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility)) {
			AActor* HitActor = HitResult.GetActor();
			if (HitResult.GetActor()->GetComponentByClass(UPushableObjectComponent::StaticClass())) {
				UPushableObjectComponent* pushableComponent = Cast<UPushableObjectComponent>(HitResult.GetActor()->GetComponentByClass(UPushableObjectComponent::StaticClass()));
				FVector MovementDirection;

				if (pushableComponent->IsRailedObject) {
					MovementDirection = -(HitResult.Normal);
					if (MovementDirection.X == MovementDirection.Y)
						return;
				}

				else
				{
					MovementDirection = HitActor->GetActorLocation() - GetOwner()->GetActorLocation();
					MovementDirection.Normalize();
					MovementDirection.Z = 0;
				}

				HitActor->SetActorLocation(HitActor->GetActorLocation() + MovementDirection * DeltaTime * (pushableComponent->IsRailedObject ? RailedPushForce : UnRailedPushForce));
			}
		}
	}
}

