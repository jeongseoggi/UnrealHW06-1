#include "DisappearActor.h"
#include "RobotCharacter.h"

// Sets default values
ADisappearActor::ADisappearActor()
{
	PrimaryActorTick.bCanEverTick = false;

	
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(SceneComp);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComp);

	// 유료 에셋 제거로 인해 해당 부분 주석
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("/Game/Warehouse/Assets/Props/WM00218-Unwrapped_Boxes/SM_WM00218-Unwrapped_Box_Open.SM_WM00218-Unwrapped_Box_Open"));

	if (Mesh.Succeeded())
	{
		StaticMesh->SetStaticMesh(Mesh.Object);
	}*/

	StaticMesh->OnComponentHit.AddDynamic(this, &ADisappearActor::OnHit);

	disappearTime = FMath::RandRange(2.5f, 3.5f);
}

// Called when the game starts or when spawned
void ADisappearActor::BeginPlay()
{
	Super::BeginPlay();
	
	

	UE_LOG(LogTemp, Log, TEXT("%f"), disappearTime);

}

void ADisappearActor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// 플레이어블 캐릭터를 만들면 여기에 플레이블 캐릭터 히트 시 타이머 작동
	ARobotCharacter* Player = Cast<ARobotCharacter>(OtherActor);
	FTimerHandle handler;

	UE_LOG(LogTemp, Log, TEXT("Hit"));

	if (IsValid(Player))
	{
		GetWorld()->GetTimerManager().SetTimer(handler, this, &ADisappearActor::SetActiveActor, disappearTime);
	}
}

void ADisappearActor::SetActiveActor()
{
	this->SetActorHiddenInGame(true);
	this->SetActorEnableCollision(false);
	this->SetActorTickEnabled(false);
}
 
