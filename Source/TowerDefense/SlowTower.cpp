// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowTower.h"
#include "EnemyBase.h"

ASlowTower::ASlowTower()
{

}

void ASlowTower::BeginPlay()
{
	Super::BeginPlay();
}

void ASlowTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlowTower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASlowTower::AttackEnemy(AEnemyBase* Target)
{
	Super::AttackEnemy(Target);

	Target->ApplySlowEffect(SlowEffectPercent, SlowEffectDuration);
}