// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerDefensePlayerController.h"
#include "EnemyBase.h"
#include "EngineUtils.h"
#include "EnemyAIController.h"
#include "TowerBase.h"
#include "TowerDefenseHUD.h"
#include "TowerDefenseGameModeBase.h"

ATowerDefensePlayerController::ATowerDefensePlayerController()
{

}

void ATowerDefensePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerDefensePlayerController::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	HUD = GetHUD<ATowerDefenseHUD>();

	GameMode = World->GetAuthGameMode<ATowerDefenseGameModeBase>();

	if (InputComponent)
	{
		InputComponent->BindAction(TEXT("Select"), EInputEvent::IE_Pressed, this, &ATowerDefensePlayerController::Select);
	}
}

void ATowerDefensePlayerController::Select()
{
	FHitResult HitResult;

	if (GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic, true, HitResult))
	{
		AActor* Actor = HitResult.GetActor();

		if (!Actor)
		{
			return;
		}

		if (Actor->GetName().Contains(TEXT("TowerSpawnPoint")))
		{
			SelectedTowerSpawn = Actor;

			HUD->ShowTowerBuildWidget();

			return;
		}

		ATowerBase* Tower = Cast<ATowerBase, AActor>(Actor);

		if (Tower)
		{
			SelectedTowerSpawn = nullptr;

			HUD->ShowTowerWidget(Tower);

			return;
		}

		HUD->HideWidgets();

		SelectedTowerSpawn = nullptr;
	}
}

void ATowerDefensePlayerController::SpawnTower(TSubclassOf<ATowerBase> TowerType, int32 Price)
{
	check(TowerType);

	if (Price > GameMode->GetMoney())
	{
		return;
	}

	FTransform Transform = SelectedTowerSpawn->GetTransform();
	FVector Location = Transform.GetLocation();
	Location.Z = 126.0;
	Transform.SetLocation(Location);
	Transform.SetScale3D(FVector(1.0, 1.0, 1.0));

	SelectedTowerSpawn->Destroy();
	SelectedTowerSpawn = nullptr;

	ATowerBase* Tower = World->SpawnActor<ATowerBase>(TowerType, Transform);

	GameMode->ChangeMoney(Price * (-1));

	HUD->ShowTowerWidget(Tower);
}
