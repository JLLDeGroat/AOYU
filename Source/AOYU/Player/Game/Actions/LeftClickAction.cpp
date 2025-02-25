// Fill out your copyright notice in the Description page of Project Settings.

#include "LeftClickAction.h"
#include "VgCore/Domain/Debug/DebugMessages.h"

ULeftClickAction::ULeftClickAction(const FObjectInitializer &ObjectInitializer) : UActorComponent(ObjectInitializer)
{

    PrimaryComponentTick.bCanEverTick = false;
}

void ULeftClickAction::BeginPlay()
{
    Super::BeginPlay();
}

void ULeftClickAction::DoAction()
{
    UDebugMessages::LogDisplay(this, "DoAction");
}