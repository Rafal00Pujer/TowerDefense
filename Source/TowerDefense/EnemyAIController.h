// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

class UCrowdFollowingComponent;
class ATowerDefenseGameModeBase;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyAIController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		/// <summary>
		/// Quick access to game mode.
		/// </summary>
		ATowerDefenseGameModeBase* GameMode;

	UFUNCTION()
		/// <summary>
		/// Delayed BeginPlay because calling GetPawn returns null. Probably Controller needs 1 Tick to connect to Pawn.
		/// </summary>
		void DelayedBeginPlay();

	/// <summary>
	/// Called on movement complete.
	/// </summary>
	void OnMovementComplete(FAIRequestID RequestID, const FPathFollowingResult& Result);
};
