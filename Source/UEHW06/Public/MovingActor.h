// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class UEHW06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Properties")
	FVector StartPos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Properties")
	FVector EndPos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Properties")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Properties")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneComp;
};
