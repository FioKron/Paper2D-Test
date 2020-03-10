// Fill out your copyright notice in the Description page of Project Settings.


#include "Paper2DTest/Public/Paper2DTestEntity.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"

// Sets default values
APaper2DTestEntity::APaper2DTestEntity()
{
 	// Disable this to improve performance:
	PrimaryActorTick.bCanEverTick = true;

	AnimatedSprite = CreateDefaultSubobject<UPaperFlipbookComponent>(FName("AnimatedSprite"));
	AnimatedSprite->SetVisibility(true, true);
}


// Update:
void APaper2DTestEntity::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

// Due for overriding:
void APaper2DTestEntity::UpdateEntity(){}
void APaper2DTestEntity::UpdateAnimation(){}

