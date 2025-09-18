// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawner.generated.h"

class UBoxComponent;
class ARoundActor;
class AMovingActor;

UCLASS()
class UEHW06_API ARandomSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<ARoundActor> SpawnRoundActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AMovingActor> SpawnMovingActor;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	int32 SpawnCount = 5;



	void SpawnActorsInArea();
};
