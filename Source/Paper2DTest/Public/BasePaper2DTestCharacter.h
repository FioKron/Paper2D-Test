// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "BasePaper2DTestCharacter.generated.h"

/**
 * This class is the default character for Paper2DTest, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS()
class PAPER2DTEST_API ABasePaper2DTestCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:

	/** The animation to play while not having one's position modified. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	/** The animation to play whilst attacking. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	UPaperFlipbook* AttackingAnimation;

protected:

	virtual void Tick(float DeltaSeconds) override;
	virtual void UpdateCharacter();

	/** Called to choose the correct animation to play based on the character's state */
	virtual void UpdateAnimation();
};
