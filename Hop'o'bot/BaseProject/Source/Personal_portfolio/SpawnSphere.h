#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnSphere.generated.h"

// Fill out your copyright notice in the Description page of Project Settings.

UCLASS()
class PERSONAL_PORTFOLIO_API ASpawnSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnSphere();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	void ScheduleActorSpawn();

private:
	UFUNCTION()
	void SpawnActorShceduled();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool SpawnOverTime = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.0f;

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* SpawnBox;

	FTimerHandle SpawnTimerHandle;
};
