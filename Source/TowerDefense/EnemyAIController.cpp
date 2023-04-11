// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "EngineUtils.h"
#include "Navigation/PathFollowingComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "TowerDefenseGameModeBase.h"

AEnemyAIController::AEnemyAIController()
{

}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &AEnemyAIController::DelayedBeginPlay); // Setup DelayedBeginPlay.
}

void AEnemyAIController::DelayedBeginPlay()
{
	GameMode = GetWorld()->GetAuthGameMode<ATowerDefenseGameModeBase>();

	AActor* StopPoint = GameMode->GetStopPoint();

	UPathFollowingComponent* PathFollowingComp = GetPathFollowingComponent();

	EPathFollowingRequestResult::Type result = MoveToActor(StopPoint, 10.0);

	if (EPathFollowingRequestResult::Type::Failed == result)
	{
		return;
	}

	PathFollowingComp->OnRequestFinished.AddUObject(this, &AEnemyAIController::OnMovementComplete);
}

void AEnemyAIController::OnMovementComplete(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	GameMode->ChangeLife(-1);

	APawn* ControlledPawn = GetPawn();

	ControlledPawn->Destroy();
}