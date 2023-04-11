// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TowerBase.generated.h"

class AEnemyBase;
class ATowerDefenseGameModeBase;
class UParticleSystemComponent;

/// <summary>
/// Types of tower upgrade.
/// </summary>
namespace ETowerUpgrade
{
	/// <summary>
	/// Types of tower upgrade.
	/// </summary>
	enum Type
	{
		/// <summary>
		/// Damage upgrade.
		/// </summary>
		Damage,

		/// <summary>
		/// Range upgrade.
		/// </summary>
		Range,

		/// <summary>
		/// Armor piercing upgrade.
		/// </summary>
		ArmorPiercing
	};
}

UCLASS()
class TOWERDEFENSE_API ATowerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATowerBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// <summary>
	/// Quick access to Range Collision Mesh, that is used for finding targets at Range.
	/// </summary>
	/// <returns>Range Collision Mesh</returns>
	UStaticMeshComponent* GetRangeCollisionMesh();

	/// <summary>
	/// Attacks selected enemy.
	/// </summary>
	/// <param name="Target">Target to attack.</param>
	virtual void AttackEnemy(AEnemyBase* Target);

	/// <summary>
	/// Gets attack cooldown of this tower.
	/// </summary>
	/// <returns>Attack Cooldown.</returns>
	float GetAttackCooldown();

	/// <summary>
	/// Gets tower name.
	/// </summary>
	/// <returns>Tower name.</returns>
	FString GetTowerName();

	/// <summary>
	/// Gets tower damage.
	/// </summary>
	/// <returns>Tower damage.</returns>
	float GetTowerDamage();

	/// <summary>
	/// Gets damage upgrade level.
	/// </summary>
	/// <returns>Damage upgrade level.</returns>
	int32 GetDamageUpgradeLevel();

	/// <summary>
	/// Get damage upgrade price.
	/// </summary>
	/// <returns>Damage upgrade price.</returns>
	int32 GetDamageUpgradePrice();

	/// <summary>
	/// Gets tower range.
	/// </summary>
	/// <returns>Tower Range.</returns>
	float GetTowerRange();

	/// <summary>
	/// Gets range upgrade level.
	/// </summary>
	/// <returns>Range upgrade level.</returns>
	int32 GetRangeUpgradeLevel();

	/// <summary>
	/// Get range upgrade price.
	/// </summary>
	/// <returns>Range upgrade price.</returns>
	int32 GetRangeUpgradePrice();

	/// <summary>
	/// Gets tower armor piercing.
	/// </summary>
	/// <returns>Tower armor piercing.</returns>
	int32 GetTowerArmorPiercing();

	/// <summary>
	/// Gets armor piercing upgrade level.
	/// </summary>
	/// <returns>Armor piercing upgrade level.</returns>
	int32 GetArmorPiercingUpgradeLevel();

	/// <summary>
	/// Get armor piercing upgrade price.
	/// </summary>
	/// <returns>Armor piercing upgrade price.</returns>
	int32 GetArmorPiercingUpgradePrice();

	/// <summary>
	/// Upgrade tower.
	/// </summary>
	/// <param name="UpgradeType">Upgrade type.</param>
	void UpgradeTower(ETowerUpgrade::Type UpgradeType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		/// <summary>
		/// Field used to rotate tower towards target.
		/// </summary>
		AEnemyBase* LookAtTarget;

	UPROPERTY()
		/// <summary>
		/// Quick access to game mode.
		/// </summary>
		ATowerDefenseGameModeBase* GameMode;

	UPROPERTY(VisibleAnywhere)
		/// <summary>
		/// Mesh used for finding targets at Range.
		/// </summary>
		UStaticMeshComponent* RangeCollisionMesh;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Name of this tower.
		/// </summary>
		FString TowerName = "Tower Base";

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Distance used to look for targets. In meters.
		/// </summary>
		float Range = 1.0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Range upgrade factor.
		/// </summary>
		float RangeUpgradeFactor = 1.1;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Range upgrade Price.
		/// </summary>
		int32 RangeUpgradePrice = 10;

	/// <summary>
	/// Range upgrade level.
	/// </summary>
	int32 RangeUpgradeLevel = 0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Damage that this tower deals.
		/// </summary>
		float Damage = 10;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Damage upgrade factor.
		/// </summary>
		float DamageUpgradeFactor = 1.1;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Damage upgrade Price.
		/// </summary>
		int32 DamageUpgradePrice = 10;

	/// <summary>
	/// Damage upgrade level.
	/// </summary>
	int32 DamageUpgradeLevel = 0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Armor piercing.
		/// </summary>
		int32 ArmorPiercing = 0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Armor piercing upgrade factor.
		/// </summary>
		int32 ArmorPiercingUpgradeFactor = 0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Armor piercing upgrade Price.
		/// </summary>
		int32 ArmorPiercingUpgradePrice = 10;

	/// <summary>
	/// Armor piercing upgrade level.
	/// </summary>
	int32 ArmorPiercingUpgradeLevel = 0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Delay betwen attacks. In seconds.
		/// </summary>
		float AttackCooldown = 1;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Muzzle flash particle.
		/// </summary>
		UParticleSystem* MuzzleFlashParticle;

	/// <summary>
	/// Range collision mesh setup.
	/// </summary>
	void RangeCollisionMeshSetup();

	/// <summary>
	/// Scales range collision mesh based on range.
	/// </summary>
	FORCEINLINE void ScaleRangeCollisionMesh();
};
