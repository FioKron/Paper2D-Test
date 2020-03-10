// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Paper2DTestCombatEntity.h"
#include "PlasmaProjectile.generated.h"

/**
 * 
 */
UCLASS()
class PAPER2DTEST_API APlasmaProjectile : public APaper2DTestCombatEntity
{
	GENERATED_BODY()

public:

	// Properties:

	/** To handle movement of this projectile. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	class UProjectileMovementComponent* PlasmaProjectileMovementComponent;

	/** For how fast this projectile moves. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float MovementForceMultiplyer = 10.f;

	/** For the damage value of this projectile. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mechanics)
	float ProjectileDamageValue = 25.f;

	/** 
		For the time this projectile will remain in the game world if
		no collisions occur.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mechanics)
	float ProjectileLifetime = 5.f;

	// Methods:

	/** Standard constructor. */
	APlasmaProjectile();
	
protected:

	// Properties:

	FTimerHandle ProjectileLifetimeHandle;

	// Methods:

	/** For updating this entity. */
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void BeginPlay() override;
	virtual void UpdateEntity() override;
	
	/** Called to choose the correct animation to play based on the entity's state. */
	virtual void UpdateAnimation() override;
	
	/** For when time is up for this projectile. */
	void OnProjectileLifetimeExpired();
};
