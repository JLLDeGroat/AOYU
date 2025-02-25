// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LeftClickAction.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AOYU_API ULeftClickAction : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULeftClickAction(const FObjectInitializer &ObjectInitializer);

	virtual void BeginPlay() override;
	void DoAction();

protected:


private:

};
