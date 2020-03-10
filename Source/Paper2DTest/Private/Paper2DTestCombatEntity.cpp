// Fill out your copyright notice in the Description page of Project Settings.

#include "Paper2DTest/Public/Paper2DTestCombatEntity.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

// Empty for now:
APaper2DTestCombatEntity::APaper2DTestCombatEntity()
{
	BoundingBox = CreateDefaultSubobject<UBoxComponent>(FName("BoundingBox"));
	BoundingBox->SetupAttachment(AnimatedSprite);	
	BoundingBox->bAutoActivate = true;
	BoundingBox->bAutoRegister = true;
}

void APaper2DTestCombatEntity::BeginPlay()
{
	Super::BeginPlay();

	BoundingBox->WeldTo(AnimatedSprite);
	AnimatedSprite->SetRelativeLocation(FVector::ZeroVector);
	AnimatedSprite->SetWorldRotation(GetActorRotation());
}

void APaper2DTestCombatEntity::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateEntity();
}

void APaper2DTestCombatEntity::UpdateEntity()
{
	UpdateAnimation();
}

void APaper2DTestCombatEntity::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSquared = PlayerVelocity.SizeSquared();

	if (PlayerSpeedSquared > 0 && AnimatedSprite && MovingAnimation &&
		!AnimatedSprite->IsPlaying())
	{
		AnimatedSprite->SetFlipbook(MovingAnimation);
		AnimatedSprite->PlayFromStart();
	}
	else if (PlayerSpeedSquared < 0 && AnimatedSprite && IdleAnimation)
	{
		AnimatedSprite->SetFlipbook(IdleAnimation);
		AnimatedSprite->PlayFromStart();
	}
}
