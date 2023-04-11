// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TowerAIController.generated.h"

class ATowerBase;
class AEnemyBase;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API ATowerAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATowerAIController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		/// <summary>
		/// Quick access to world.
		/// </summary>
		UWorld* World;

	UPROPERTY()
		/// <summary>
		/// Controlled Tower.
		/// </summary>
		ATowerBase* ControlledTower;

	UPROPERTY()
		/// <summary>
		/// List of enemies available to target.
		/// </summary>
		TArray<AEnemyBase*> AvailableTargets;

	UPROPERTY()
		/// <summary>
		/// Timer handle for attack cooldown.
		/// </summary>
		FTimerHandle AttackTimerHandle;

	UPROPERTY()
		/// <summary>
		/// Target of attack.
		/// </summary>
		AEnemyBase* Target;

	UFUNCTION()
		/// <summary>
		/// Delayed BeginPlay because calling GetPawn returns null. Probably Controller needs 1 Tick to connect to Pawn.
		/// </summary>
		void DelayedBeginPlay();

	UFUNCTION()
		/// <summary>
		/// Adds enemy to AvailableTargets on begin overlap event. Calls StartAttackin if attack isn't on cooldown.
		/// </summary>
		void AddEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		/// <summary>
		/// Removes enemy from AvailableTargets on end overlap event.
		/// </summary>
		void RemoveEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		/// <summary>
		/// Handles tower attack.
		/// </summary>
		void HandleAttack();

	/// <summary>
	/// Starts attack loop.
	/// </summary>
	FORCEINLINE void StartAttacking();
};
