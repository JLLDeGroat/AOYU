// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GamePawn.generated.h"

class UCapsuleComponent;
class UCameraComponent;

UCLASS()
class AOYU_API AGamePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGamePawn(const FObjectInitializer& ObjectInitializer);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCapsuleComponent *CapsuleComponent;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent *Camera;
};
