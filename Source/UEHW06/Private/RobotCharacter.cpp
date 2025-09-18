#include "RobotCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "RobotPlayerController.h"
#include "EnhancedInputComponent.h"

// Sets default values
ARobotCharacter::ARobotCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ARobotCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARobotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ARobotPlayerController* PlayerController = Cast<ARobotPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedComponent->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &ARobotCharacter::Move);
			}

			if (PlayerController->LookAction)
			{
				EnhancedComponent->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, this, &ARobotCharacter::Look);
			}

			if (PlayerController->JumpAction)
			{
				EnhancedComponent->BindAction(PlayerController->JumpAction, ETriggerEvent::Triggered, this, &ARobotCharacter::Jump);
			}
		}
	}

}

void ARobotCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller)
	{
		return;
	}

	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void ARobotCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookInput = Value.Get<FVector2D>();

	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}

void ARobotCharacter::Jump(const FInputActionValue& Value)
{
	if (Value.Get<bool>())
	{
		ACharacter::Jump();
	}
}

