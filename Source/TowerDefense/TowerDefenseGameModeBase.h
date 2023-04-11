// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TowerDefenseGameModeBase.generated.h"

class AEnemyBase;
class ATowerBase;
class ATowerDefenseHUD;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API ATowerDefenseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATowerDefenseGameModeBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Stop Point is used for final location on lane.
	/// </summary>
	/// <returns>Stop Point Actor</returns>
	AActor* GetStopPoint();

	/// <summary>
	/// Gets money.
	/// </summary>
	/// <returns>Money</returns>
	int32 GetMoney();

	/// <summary>
	/// Change money.
	/// </summary>
	/// <param name="Amount">Amount.</param>
	void ChangeMoney(int32 Amount);

	/// <summary>
	/// Gets life.
	/// </summary>
	/// <returns>Life.</returns>
	int32 GetLife();

	/// <summary>
	/// Change life.
	/// </summary>
	/// <param name="Amount">Amount.</param>
	void ChangeLife(int32 Amount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Enemy types to spawn at Enemy Spawn Rate.
		/// </summary>
		TArray<TSubclassOf<AEnemyBase>> EnemyTypes;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Time between enemy spawns.
		/// </summary>
		float EnemySpawnRate = 1.0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// First spawn delay.
		/// </summary>
		float FirstSpawnDelay = 1.0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Money.
		/// </summary>
		int32 Money = 1000;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Life.
		/// </summary>
		int32 Life = 10;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Name of Start Point Actor on level.
		/// </summary>
		FString StartPointName;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Name of Stop Point Actor on level.
		/// </summary>
		FString StopPointName;

	UPROPERTY()
		/// <summary>
		/// Qiuck acces to World.
		/// </summary>
		UWorld* World;

	UPROPERTY()
		/// <summary>
		/// Qiuck acces to HUD.
		/// </summary>
		ATowerDefenseHUD* HUD;

	UPROPERTY()
		/// <summary>
		/// Pointer to Start Point Actor.
		/// </summary>
		AActor* StartPointActor;

	UPROPERTY()
		/// <summary>
		/// Pointer to Stop Point Actor.
		/// </summary>
		AActor* StopPointActor;

	UPROPERTY()
		/// <summary>
		/// Handler for Enemy Spawn Timer.
		/// </summary>
		FTimerHandle EnemySpawnTimer;

	UFUNCTION()
		/// <summary>
		/// Delegate function for spawning enemies at EnemySpawnRate.
		/// </summary>
		void SpawnEnemy();
};
