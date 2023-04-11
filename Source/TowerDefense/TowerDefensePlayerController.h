// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TowerDefensePlayerController.generated.h"

class AEnemyBase;
class ATowerBase;
class ATowerDefenseHUD;
class ATowerDefenseGameModeBase;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API ATowerDefensePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATowerDefensePlayerController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Spawns tower at selected tower spawn.
	/// </summary>
	/// <param name="TowerType">Tower type to spwan</param>
	/// /// <param name="Price">Price of tower.</param>
	void SpawnTower(TSubclassOf<ATowerBase> TowerType, int32 Price);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		/// <summary>
		/// Qiuck acces to World.
		/// </summary>
		UWorld* World;

	UPROPERTY()
		/// <summary>
		/// Qiuck acces to game mode.
		/// </summary>
		ATowerDefenseGameModeBase* GameMode;

	UPROPERTY()
		/// <summary>
		/// Qiuck acces to HUD.
		/// </summary>
		ATowerDefenseHUD* HUD;

	UPROPERTY()
		/// <summary>
		/// Selected tower spawn.
		/// </summary>
		AActor* SelectedTowerSpawn;

	UFUNCTION()
		/// <summary>
		/// Select action input handle.
		/// </summary>
		void Select();
};
