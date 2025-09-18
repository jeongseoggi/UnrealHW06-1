// Fill out your copyright notice in the Description page of Project Settings.


#include "RoundActor.h"

// Sets default values
ARoundActor::ARoundActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(SceneComp);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComp);

	// 유료 에셋 제거로 인해 해당 부분 주석
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("/Game/Warehouse/Assets/Props/WM00222-Round_Container/SM_WM00222-Round_Container_single.SM_WM00222-Round_Container_single"));

	if (Mesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(Mesh.Object);
	}*/

	RotateSpeed = FMath::RandRange(45.0f, 90.0f);
}

// Called when the game starts or when spawned
void ARoundActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(15.0f, 15.0f, 15.0f));
}

// Called every frame
void ARoundActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, RotateSpeed * DeltaTime, 0));
}

