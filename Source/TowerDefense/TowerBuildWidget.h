// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TowerBuildWidget.generated.h"

class UButton;
class ATowerDefensePlayerController;
class ATowerBase;
class UTextBlock;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API UTowerBuildWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UTowerBuildWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditAnywhere)
		/// <summary>
		/// First tower type.
		/// </summary>
		TSubclassOf<ATowerBase> FirstTowerType;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// First tower price.
		/// </summary>
		int32 FirstTowerPrice = 100;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Build first tower button.
		/// </summary>
		UButton* BuildFirstTowerButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Build first tower Text.
		/// </summary>
		UTextBlock* BuildFirstTowerText;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Second tower type.
		/// </summary>
		TSubclassOf<ATowerBase> SecondTowerType;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Second tower price.
		/// </summary>
		int32 SecondTowerPrice = 100;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Build second tower button.
		/// </summary>
		UButton* BuildSecondTowerButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Build second tower Text.
		/// </summary>
		UTextBlock* BuildSecondTowerText;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Third tower type.
		/// </summary>
		TSubclassOf<ATowerBase> ThirdTowerType;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Third tower price.
		/// </summary>
		int32 ThirdTowerPrice = 100;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Build third tower button.
		/// </summary>
		UButton* BuildThirdTowerButton;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Build third tower Text.
		/// </summary>
		UTextBlock* BuildThirdTowerText;

	UFUNCTION()
		/// <summary>
		/// Build first tower.
		/// </summary>
		void BuildFirstTower();

	UFUNCTION()
		/// <summary>
		/// Build second tower.
		/// </summary>
		void BuildSecondTower();

	UFUNCTION()
		/// <summary>
		/// Build third tower.
		/// </summary>
		void BuildThirdTower();

	UPROPERTY()
		/// <summary>
		/// Quick acces to player controller.
		/// </summary>
		ATowerDefensePlayerController* PlayerController;
};
