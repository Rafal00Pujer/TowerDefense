// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerWidget.h"
#include "TowerBase.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

UTowerWidget::UTowerWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UTowerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	DamageUpgradeButton->SetPressMethod(EButtonPressMethod::DownAndUp);
	DamageUpgradeButton->OnPressed.AddUniqueDynamic(this, &UTowerWidget::UpgradeDamage);

	RangeUpgradeButton->SetPressMethod(EButtonPressMethod::DownAndUp);
	RangeUpgradeButton->OnPressed.AddUniqueDynamic(this, &UTowerWidget::UpgradeRange);

	ArmorPiercingUpgradeButton->SetPressMethod(EButtonPressMethod::DownAndUp);
	ArmorPiercingUpgradeButton->OnPressed.AddUniqueDynamic(this, &UTowerWidget::UpgradeArmorPiercing);
}

void UTowerWidget::ShowTowerInfo(ATowerBase* Tower)
{
	check(Tower);

	SelectedTower = Tower;

	TowerName->SetText(FText::AsCultureInvariant(SelectedTower->GetTowerName()));
	TowerDamage->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Damage %s"), *FString::SanitizeFloat(SelectedTower->GetTowerDamage()))));
	TowerRange->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Range %s m"), *FString::SanitizeFloat(SelectedTower->GetTowerRange()))));
	TowerArmorPiercing->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Armor Piercing %i"), SelectedTower->GetTowerArmorPiercing())));
	DamageUpgradeText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Upgrade Damage Price %i$"), SelectedTower->GetDamageUpgradePrice())));
	RangeUpgradeText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Upgrade Range Price %i$"), SelectedTower->GetRangeUpgradePrice())));
	ArmorPiercingUpgradeText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Upgrade Armor Piercing Price %i$"), SelectedTower->GetArmorPiercingUpgradePrice())));

	if (SelectedTower->GetDamageUpgradeLevel() < 3)
	{
		DamageUpgradeButton->SetIsEnabled(true);
	}
	else
	{
		DamageUpgradeButton->SetIsEnabled(false);
	}

	if (SelectedTower->GetRangeUpgradeLevel() < 3)
	{
		RangeUpgradeButton->SetIsEnabled(true);
	}
	else
	{
		RangeUpgradeButton->SetIsEnabled(false);
	}

	if (SelectedTower->GetArmorPiercingUpgradeLevel() < 3)
	{
		ArmorPiercingUpgradeButton->SetIsEnabled(true);
	}
	else
	{
		ArmorPiercingUpgradeButton->SetIsEnabled(false);
	}
}

void UTowerWidget::HideTowerInfo()
{
	SelectedTower = nullptr;
}

void UTowerWidget::UpgradeDamage()
{
	SelectedTower->UpgradeTower(ETowerUpgrade::Damage);

	TowerDamage->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Damage %s"), *FString::SanitizeFloat(SelectedTower->GetTowerDamage()))));

	if (SelectedTower->GetDamageUpgradeLevel() < 3)
	{
		DamageUpgradeButton->SetIsEnabled(true);
	}
	else
	{
		DamageUpgradeButton->SetIsEnabled(false);
	}
}

void UTowerWidget::UpgradeRange()
{
	SelectedTower->UpgradeTower(ETowerUpgrade::Range);

	TowerRange->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Range %s m"), *FString::SanitizeFloat(SelectedTower->GetTowerRange()))));

	if (SelectedTower->GetRangeUpgradeLevel() < 3)
	{
		RangeUpgradeButton->SetIsEnabled(true);
	}
	else
	{
		RangeUpgradeButton->SetIsEnabled(false);
	}
}

void UTowerWidget::UpgradeArmorPiercing()
{
	SelectedTower->UpgradeTower(ETowerUpgrade::ArmorPiercing);

	TowerArmorPiercing->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Armor Piercing %i"), SelectedTower->GetTowerArmorPiercing())));

	if (SelectedTower->GetArmorPiercingUpgradeLevel() < 3)
	{
		ArmorPiercingUpgradeButton->SetIsEnabled(true);
	}
	else
	{
		ArmorPiercingUpgradeButton->SetIsEnabled(false);
	}
}
