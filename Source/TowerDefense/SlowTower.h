// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "SlowTower.generated.h"

class AEnemyBase;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API ASlowTower : public ATowerBase
{
	GENERATED_BODY()

public:
	ASlowTower();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// <summary>
	/// Attacks selected enemy and applies slow effect.
	/// </summary>
	/// <param name="Target">Target to attack.</param>
	virtual void AttackEnemy(AEnemyBase* Target) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Percentage by which to reduce the movement speed. 
		/// </summary>
		float SlowEffectPercent = 0.1;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Duration of slow effect. In seconds.
		/// </summary>
		float SlowEffectDuration = 0.1;
};
