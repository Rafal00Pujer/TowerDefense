// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TowerDefenseHUD.generated.h"

class UTowerWidget;
class UMainWidget;
class ATowerBase;
class UTowerBuildWidget;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API ATowerDefenseHUD : public AHUD
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATowerDefenseHUD();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Shows tower widget for selected tower.
	/// </summary>
	/// <param name="Tower">Tower for which to show the widget.</param>
	void ShowTowerWidget(ATowerBase* Tower);

	/// <summary>
	/// Shows tower build widget.
	/// </summary>
	void ShowTowerBuildWidget();

	/// <summary>
	/// Hides all widgets.
	/// </summary>
	void HideWidgets();

	/// <summary>
	/// Shows money.
	/// </summary>
	/// <param name="Money">Money to show.</param>
	void ShowMoney(int32 Money);

	/// <summary>
	/// Shows life.
	/// </summary>
	/// <param name="Life">Life to show.</param>
	void ShowLife(int32 Life);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Main widget Type.
		/// </summary>
		TSubclassOf<UMainWidget> MainWidgetType;

	UPROPERTY()
		/// <summary>
		/// Quick access to main widget.
		/// </summary>
		UMainWidget* MainWidget;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Tower widget Type.
		/// </summary>
		TSubclassOf<UTowerWidget> TowerWidgetType;

	UPROPERTY()
		/// <summary>
		/// Quick access to tower widget.
		/// </summary>
		UTowerWidget* TowerWidget;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Tower build widget Type.
		/// </summary>
		TSubclassOf<UTowerBuildWidget> TowerBuildWidgetType;

	UPROPERTY()
		/// <summary>
		/// Quick access to tower build widget.
		/// </summary>
		UTowerBuildWidget* TowerBuildWidget;
};
