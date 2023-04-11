// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TowerBase.h"
#include "HeavyTower.generated.h"

class AEnemyBase;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API AHeavyTower : public ATowerBase
{
	GENERATED_BODY()

public:
	AHeavyTower();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// <summary>
	/// Attacks selected enemy.
	/// </summary>
	/// <param name="Target">Target to attack.</param>
	virtual void AttackEnemy(AEnemyBase* Target) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		/// <summary>
		/// Mesh used for damaging targets at explosive range.
		/// </summary>
		UStaticMeshComponent* ExplosiveCollisionMesh;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Range of explosive. In meters.
		/// </summary>
		float ExplosiveRange = 1.0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Explosive damage.
		/// </summary>
		float ExplosiveDamage = 1;

	/// <summary>
	/// Explosive collision mesh setup.
	/// </summary>
	void ExplosiveCollisionMeshSetup();

	/// <summary>
	/// Scales explosive collision mesh based on explosive range.
	/// </summary>
	void ScaleExplosiveCollisionMesh();
};
