// Fill out your copyright notice in the Description page of Project Settings.

#include "GamePlayerController.h"
#include "Actions/LeftClickAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "VgCore/Domain/Debug/DebugMessages.h"

AGamePlayerController::AGamePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;

	PlayerInputMappingContext = LoadObject<UInputMappingContext>(this, TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Controls/InputMapping.InputMapping'"));
	ClickAction = LoadObject<UInputAction>(this, TEXT("/Script/EnhancedInput.InputAction'/Game/Controls/IA_LeftClick.IA_LeftClick'"));
	MoveRightAction = LoadObject<UInputAction>(this, TEXT("/Script/EnhancedInput.InputAction'/Game/Controls/IA_MoveRight.IA_MoveRight'"));
	MoveUpAction = LoadObject<UInputAction>(this, TEXT("/Script/EnhancedInput.InputAction'/Game/Controls/IA_MoveUp.IA_MoveUp'"));

	LeftClickActionComponent = CreateDefaultSubobject<ULeftClickAction>(TEXT("LeftClickAction"));

	MovementMultiplier = 10;
}

void AGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerInputMappingContext, 0);
	}
}

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent *EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup touch input events
		EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Started, LeftClickActionComponent, &ULeftClickAction::DoAction);
		EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &AGamePlayerController::MoveUp_Started);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AGamePlayerController::MoveRight_Started);
	}
	else
	{
		UDebugMessages::LogError(this, "Failed to use, enhanced Input Component");
	}
}

void AGamePlayerController::MoveUp_Started(const FInputActionValue &Value)
{
	GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + FVector(Value.Get<float>() * MovementMultiplier, 0, 0));
}

void AGamePlayerController::MoveRight_Started(const FInputActionValue &Value)
{
	GetPawn()->SetActorLocation(GetPawn()->GetActorLocation() + FVector(0, Value.Get<float>() * MovementMultiplier, 0));
}