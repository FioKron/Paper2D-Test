// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paper2D/Classes/PaperSpriteActor.h"
#include "Paper2DTestEntity.generated.h"

UCLASS()
class PAPER2DTEST_API APaper2DTestEntity : public APaperSpriteActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaper2DTestEntity();

	/** The animation to play while not having one's position modified. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	/** The animation to play whilst moving. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* MovingAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbookComponent* AnimatedSprite;

protected:

	// Methods:
	
	/** For updating this entity. */
	virtual void Tick(float DeltaSeconds) override;
	virtual void UpdateEntity();
	/** Called to choose the correct animation to play based on the entity's state. */
	virtual void UpdateAnimation();
};
