// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_InventoryComponent.h"
#include "CPP_InteractableComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UCPP_InventoryComponent::UCPP_InventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UCPP_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UCPP_InventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCPP_InventoryComponent::PickUpItem(UCPP_InteractableComponent* Item)
{
    if (!CarriedItem && Item && !Item->bIsPickedUp)
    {
        CarriedItem = Item;
        AActor* Picker = GetOwner();
        Item->OnPickedUp(Picker);
    }
}

void UCPP_InventoryComponent::PlaceItem(FVector Location)
{
    if (CarriedItem)
    {
        CarriedItem->OnPlaced(Location);
        CarriedItem = nullptr;
    }
}

void UCPP_InventoryComponent::TryInteract(UCameraComponent* CameraComponent)
{
    if (!CameraComponent || CarriedItem) return;

    FVector Start = CameraComponent->GetComponentLocation();
    FVector End = Start + CameraComponent->GetForwardVector() * 300.0f;

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(GetOwner());

    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    {
        AActor* HitActor = Hit.GetActor();
        if (HitActor)
        {
            UCPP_InteractableComponent* Interactable = HitActor->FindComponentByClass<UCPP_InteractableComponent>();
            if (Interactable && !Interactable->bIsPickedUp)
            {
                PickUpItem(Interactable);
                UE_LOG(LogClass, Log, TEXT("Hit"), Hit.Component);
            }
        }
    }
}