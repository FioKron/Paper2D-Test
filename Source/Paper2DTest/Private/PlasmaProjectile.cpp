// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/ProjectileMovementComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "PlasmaProjectile.h"

APlasmaProjectile::APlasmaProjectile()
{
	PlasmaProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
		FName("PlasmaProjectileMovementComponent"));
}

void APlasmaProjectile::BeginPlay()
{
	Super::BeginPlay();
	AActor* ProjectileOwner = GetOwner();

	if (PlasmaProjectileMovementComponent && ProjectileOwner)
	{
		PlasmaProjectileMovementComponent->AddForce(
			ProjectileOwner->GetActorForwardVector() * MovementForceMultiplyer);
	}

	// Set up this projectile for destruction:
	GetWorld()->GetTimerManager().SetTimer(ProjectileLifetimeHandle, this, 
		&APlasmaProjectile::OnProjectileLifetimeExpired, ProjectileLifetime, false);
}

void APlasmaProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateEntity();
}

void APlasmaProjectile::UpdateEntity()
{
	UpdateAnimation();
}

void APlasmaProjectile::UpdateAnimation()
{
	const FVector ProjectileVelocity = GetVelocity();
	const float ProjectileSpeedSquared = ProjectileVelocity.SizeSquared();
}

void APlasmaProjectile::OnProjectileLifetimeExpired()
{
	Destroy();
}
