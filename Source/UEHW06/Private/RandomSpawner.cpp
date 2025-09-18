// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomSpawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "RoundActor.h"
#include "MovingActor.h"

// Sets default values
ARandomSpawner::ARandomSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComponent);
}

// Called when the game starts or when spawned
void ARandomSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnActorsInArea();
}

void ARandomSpawner::SpawnActorsInArea()
{
	for (int i = 0; i < SpawnCount; i++)
	{
		#pragma region InternetSearchCode
		const FVector Origin = BoxComponent->GetComponentLocation(); // BoxComponent�� ��ġ �� ��������
		const FVector Extent = BoxComponent->GetScaledBoxExtent();

		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent); //���� ��ġ �̱�


		FRotator SpawnRotation = FRotator(0.f, FMath::FRandRange(0.f, 360.f), 0.f); // ���� ȸ�� �� �̱�
		#pragma endregion

		// ���� ��ȯ (0 -> �����̴� ���� 1-> ���� ����)
		int spawnActor = FMath::RandRange(0, 1);
		

		if (spawnActor == 0)
		{
			GetWorld()->SpawnActor<AMovingActor>(SpawnMovingActor, SpawnLocation, SpawnRotation);
		}
		else
		{
			GetWorld()->SpawnActor<ARoundActor>(SpawnRoundActor, SpawnLocation, SpawnRotation);
		}
	}
}


