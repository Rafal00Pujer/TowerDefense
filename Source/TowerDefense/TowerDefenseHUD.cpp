// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefenseHUD.h"
#include "TowerWidget.h"
#include "MainWidget.h"
#include "TowerBase.h"
#include "TowerDefenseGameModeBase.h"
#include "TowerBuildWidget.h"

ATowerDefenseHUD::ATowerDefenseHUD()
{

}

void ATowerDefenseHUD::BeginPlay()
{
	Super::BeginPlay();

	MainWidget = CreateWidget<UMainWidget>(GetWorld(), MainWidgetType);

	MainWidget->AddToViewport();

	ATowerDefenseGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATowerDefenseGameModeBase>();

	MainWidget->ShowMoney(GameMode->GetMoney());
	MainWidget->ShowLife(GameMode->GetLife());
}

void ATowerDefenseHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerDefenseHUD::ShowTowerWidget(ATowerBase* Tower)
{
	check(Tower);

	if (TowerBuildWidget)
	{
		MainWidget->HideWidgetOnSideSlot(TowerBuildWidget);
	}

	if (TowerWidget)
	{
		TowerWidget->ShowTowerInfo(Tower);

		MainWidget->ShowWidgetOnSideSlot(TowerWidget);

		return;
	}

	TowerWidget = CreateWidget<UTowerWidget>(GetWorld(), TowerWidgetType);

	TowerWidget->ShowTowerInfo(Tower);

	MainWidget->ShowWidgetOnSideSlot(TowerWidget);
}

void ATowerDefenseHUD::ShowTowerBuildWidget()
{
	if (TowerWidget)
	{
		TowerWidget->HideTowerInfo();

		MainWidget->HideWidgetOnSideSlot(TowerWidget);
	}

	if (TowerBuildWidget)
	{
		MainWidget->ShowWidgetOnSideSlot(TowerBuildWidget);

		return;
	}

	TowerBuildWidget = CreateWidget<UTowerBuildWidget>(GetWorld(), TowerBuildWidgetType);

	MainWidget->ShowWidgetOnSideSlot(TowerBuildWidget);
}

void ATowerDefenseHUD::HideWidgets()
{
	if (TowerWidget)
	{
		TowerWidget->HideTowerInfo();

		MainWidget->HideWidgetOnSideSlot(TowerWidget);
	}

	if (TowerBuildWidget)
	{
		MainWidget->HideWidgetOnSideSlot(TowerBuildWidget);
	}
}

void ATowerDefenseHUD::ShowMoney(int32 Money)
{
	MainWidget->ShowMoney(Money);
}

void ATowerDefenseHUD::ShowLife(int32 Life)
{
	MainWidget->ShowLife(Life);
}
