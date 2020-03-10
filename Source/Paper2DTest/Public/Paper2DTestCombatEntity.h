// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Paper2DTestEntity.h"
#include "Paper2DTestCombatEntity.generated.h"

/**
 * 
 */
UCLASS()
class PAPER2DTEST_API APaper2DTestCombatEntity : public APaper2DTestEntity
{
	GENERATED_BODY()

public:
	
	// Methods:

	/** Standard constructor. */
	APaper2DTestCombatEntity();

	// Properties:

	/** To handle simple collision. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	class UBoxComponent* BoundingBox;

protected:


	// Methods:

	virtual void BeginPlay() override;
	/** For updating this entity. */
	virtual void Tick(float DeltaSeconds) override;
	virtual void UpdateEntity() override;
	/** Called to choose the correct animation to play based on the entity's state. */
	virtual void UpdateAnimation() override;
};
