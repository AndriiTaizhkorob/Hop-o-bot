// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPP_InteractableComponent.h"
#include "CPP_InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONAL_PORTFOLIO_API UCPP_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCPP_InventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCPP_InteractableComponent* CarriedItem = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void PickUpItem(UCPP_InteractableComponent* Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void PlaceItem(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void TryInteract(UCameraComponent* CameraComponent);
};
