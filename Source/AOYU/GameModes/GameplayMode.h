// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayMode.generated.h"

/**
 *
 */
UCLASS()
class AOYU_API AGameplayMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AGameplayMode();

	virtual void BeginPlay() override;

protected:

};

// Commenty comment test.