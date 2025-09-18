#include "MovingActor.h"

// Sets default values
AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(SceneComp);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComp);


	// 유료 에셋 제거로 인해 해당 부분 주석
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("/Game/Warehouse/Assets/Props/WM00217_Pallet/SM_WM00217_Pallet_Thin.SM_WM00217_Pallet_Thin"));

	//if (Mesh.Succeeded())
	//{
	//	StaticMesh->SetStaticMesh(Mesh.Object);
	//}

	MoveSpeed = FMath::RandRange(300.0f, 1000.0f);
}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartPos = GetActorLocation();

	if (FMath::IsNearlyZero(EndPos.X))
	{
		Direction = FVector(1.0f, 0, 0);
		EndPos = FVector(StartPos.X + 500.0f, StartPos.Y, StartPos.Z);
	}
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector NewLocation = GetActorLocation() + Direction * MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);

	if (FVector::Dist(GetActorLocation(), EndPos) < 10.f)
	{
		Direction *= -1.f;
		Swap(StartPos, EndPos);
	}
}

