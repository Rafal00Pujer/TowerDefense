// Copyright Epic Games, Inc. All Rights Reserved.


#include "TowerDefenseGameModeBase.h"
#include "EngineUtils.h"
#include "EnemyBase.h"
#include "TowerBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TowerDefenseHUD.h"

ATowerDefenseGameModeBase::ATowerDefenseGameModeBase()
{

}

void ATowerDefenseGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	APlayerController* PlayerController = World->GetFirstPlayerController();

	HUD = PlayerController->GetHUD<ATowerDefenseHUD>();

	for (AActor* Actor : TActorRange<AActor>(World))
	{
		FString ActorName = Actor->GetName();

		if (ActorName == StartPointName)
		{
			StartPointActor = Actor;
		}
		else if (ActorName == StopPointName)
		{
			StopPointActor = Actor;
		}
	}

	World->GetTimerManager().SetTimer(EnemySpawnTimer, this, &ATowerDefenseGameModeBase::SpawnEnemy, EnemySpawnRate, true, FirstSpawnDelay);
}

void ATowerDefenseGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AActor* ATowerDefenseGameModeBase::GetStopPoint()
{
	return StopPointActor;
}

int32 ATowerDefenseGameModeBase::GetMoney()
{
	return Money;
}

void ATowerDefenseGameModeBase::ChangeMoney(int32 Amount)
{
	Money += Amount;

	HUD->ShowMoney(Money);
}

int32 ATowerDefenseGameModeBase::GetLife()
{
	return Life;
}

void ATowerDefenseGameModeBase::ChangeLife(int32 Amount)
{
	Life += Amount;

	HUD->ShowLife(Life);
}

void ATowerDefenseGameModeBase::SpawnEnemy()
{
	int32 NumberOfTypes = EnemyTypes.Num();

	if (NumberOfTypes == 0)
	{
		return;
	}

	World->SpawnActor<AActor>(EnemyTypes[FMath::RandRange(0, NumberOfTypes - 1)], StartPointActor->GetActorTransform());
}