// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TowerWidget.generated.h"

class UTextBlock;
class UButton;
class ATowerBase;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API UTowerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UTowerWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	/// <summary>
	/// Show info about tower.
	/// </summary>
	/// <param name="Tower">Tower from which to get info.</param>
	void ShowTowerInfo(ATowerBase* Tower);

	/// <summary>
	/// Hides info about tower.
	/// </summary>
	void HideTowerInfo();

private:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Tower name text block.
		/// </summary>
		UTextBlock* TowerName;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Tower damage text block.
		/// </summary>
		UTextBlock* TowerDamage;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Damage upgrade button.
		/// </summary>
		UButton* DamageUpgradeButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Damage upgrade text block.
		/// </summary>
		UTextBlock* DamageUpgradeText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Tower range text block.
		/// </summary>
		UTextBlock* TowerRange;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Range upgrade button.
		/// </summary>
		UButton* RangeUpgradeButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Range upgrade text block.
		/// </summary>
		UTextBlock* RangeUpgradeText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Tower armor piercing text block.
		/// </summary>
		UTextBlock* TowerArmorPiercing;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Armor piercing upgrade button.
		/// </summary>
		UButton* ArmorPiercingUpgradeButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Armor piercing upgrade text block.
		/// </summary>
		UTextBlock* ArmorPiercingUpgradeText;

	/// <summary>
	/// Quick access to selected tower.
	/// </summary>
	ATowerBase* SelectedTower;

	UFUNCTION()
		/// <summary>
		/// Upgrades damage of the selected tower.
		/// </summary>
		void UpgradeDamage();

	UFUNCTION()
		/// <summary>
		/// Upgrades range of the selected tower.
		/// </summary>
		void UpgradeRange();

	UFUNCTION()
		/// <summary>
		/// Upgrades armor piercing of the selected tower.
		/// </summary>
		void UpgradeArmorPiercing();
};
