// Fill out your copyright notice in the Description page of Project Settings.


#include "RayCastComponent.h"

// Sets default values for this component's properties
URayCastComponent::URayCastComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void URayCastComponent::BeginPlay()
{
	Super::BeginPlay();


	
}



void URayCastComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	RayCast();
}


void URayCastComponent::RayCast()
{
	FHitResult* hit = new FHitResult();
	FVector down = GetOwner()->GetActorUpVector() * -1;
	FVector start = GetOwner()->GetActorLocation() - FVector(0, 0, 80.f);
	//FVector end = (down * 10.f) + start;
	FVector end = start - FVector(0, 0, 20.f);
	FCollisionQueryParams col;
	col.AddIgnoredActor(GetOwner());

	bool _hit = GetWorld()->LineTraceSingleByChannel(*hit, start, end, ECC_WorldStatic, col);

	HitPresent = _hit;
	


	if (_hit)
	{
		//DrawDebugLine(GetWorld(), start, end, FColor::Red, true);

		if (hit->GetActor() != NULL)
		{
			//UE_LOG(LogClass, Log, TEXT("Hit"), *hit->GetComponent()->GetName());
		}
	}
}
