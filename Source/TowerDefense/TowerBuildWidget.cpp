// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerBuildWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "TowerDefensePlayerController.h"
#include "TowerBase.h"

UTowerBuildWidget::UTowerBuildWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UTowerBuildWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BuildFirstTowerButton->SetPressMethod(EButtonPressMethod::DownAndUp);
	BuildFirstTowerButton->OnPressed.AddUniqueDynamic(this, &UTowerBuildWidget::BuildFirstTower);
	BuildFirstTowerText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Build Standard Tower Price %i$"), FirstTowerPrice)));

	BuildSecondTowerButton->SetPressMethod(EButtonPressMethod::DownAndUp);
	BuildSecondTowerButton->OnPressed.AddUniqueDynamic(this, &UTowerBuildWidget::BuildSecondTower);
	BuildSecondTowerText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Build Slow Tower Price %i$"), SecondTowerPrice)));

	BuildThirdTowerButton->SetPressMethod(EButtonPressMethod::DownAndUp);
	BuildThirdTowerButton->OnPressed.AddUniqueDynamic(this, &UTowerBuildWidget::BuildThirdTower);
	BuildThirdTowerText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Build Heavy Tower Price %i$"), ThirdTowerPrice)));

	PlayerController = GetWorld()->GetFirstPlayerController<ATowerDefensePlayerController>();
}

void UTowerBuildWidget::BuildFirstTower()
{
	PlayerController->SpawnTower(FirstTowerType, FirstTowerPrice);
}

void UTowerBuildWidget::BuildSecondTower()
{
	PlayerController->SpawnTower(SecondTowerType, SecondTowerPrice);
}

void UTowerBuildWidget::BuildThirdTower()
{
	PlayerController->SpawnTower(ThirdTowerType, ThirdTowerPrice);
}
