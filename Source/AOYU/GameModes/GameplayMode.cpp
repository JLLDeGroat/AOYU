// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayMode.h"
#include "../Player/Game/GamePawn.h"
#include "../Player/Game/GamePlayerController.h"

AGameplayMode::AGameplayMode()
{
	PlayerControllerClass = AGamePlayerController::StaticClass();
	DefaultPawnClass = AGamePawn::StaticClass();
	// HUDClass = AGameHud::StaticClass();
}

void AGameplayMode::BeginPlay()
{
	Super::BeginPlay();
}