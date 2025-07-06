// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_InteractableComponent.h"

// Sets default values for this component's properties
UCPP_InteractableComponent::UCPP_InteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UCPP_InteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UCPP_InteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_InteractableComponent::OnPickedUp(AActor* Picker)
{
	bIsPickedUp = true;
	GetOwner()->AttachToActor(Picker, FAttachmentTransformRules::KeepWorldTransform);
	GetOwner()->SetActorHiddenInGame(true);
	//GetOwner()->SetActorEnableCollision(false);

	if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()))
	{
		Root->SetSimulatePhysics(false);
		Root->SetEnableGravity(false);
	}
}

void UCPP_InteractableComponent::OnPlaced(FVector Location)
{
	bIsPickedUp = false;

	// Detach first
	GetOwner()->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	// Move the actor
	GetOwner()->SetActorLocation(Location, false, nullptr, ETeleportType::TeleportPhysics);
	GetOwner()->SetActorHiddenInGame(false);

	// Reactivate physics
	if (UPrimitiveComponent* Root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()))
	{
		Root->SetSimulatePhysics(true);
		Root->SetEnableGravity(true);
	}

	// Debug
	UE_LOG(LogTemp, Warning, TEXT("Placed item at: %s"), *Location.ToString());
}

