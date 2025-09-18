// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisappearActor.generated.h"

UCLASS()
class UEHW06_API ADisappearActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisappearActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	void SetActiveActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Properties")
	float disappearTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneComp;

};
