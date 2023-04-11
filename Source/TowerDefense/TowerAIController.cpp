// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerAIController.h"
#include "TowerBase.h"
#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"

ATowerAIController::ATowerAIController()
{

}

void ATowerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATowerAIController::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	World->GetTimerManager().SetTimerForNextTick(this, &ATowerAIController::DelayedBeginPlay);  // Setup DelayedBeginPlay.
}

void ATowerAIController::DelayedBeginPlay()
{
	ControlledTower = Cast<ATowerBase, APawn>(GetPawn());

	UStaticMeshComponent* RangeCollisionMesh = ControlledTower->GetRangeCollisionMesh();

	TArray<AActor*> OverlappingActors;
	RangeCollisionMesh->GetOverlappingActors(OverlappingActors, TSubclassOf<AActor>(AEnemyBase::StaticClass()));

	if (OverlappingActors.Num() > 0)
	{
		for (AActor* Actor : OverlappingActors)
		{
			AvailableTargets.AddUnique(Cast<AEnemyBase, AActor>(Actor));
		}

		StartAttacking();
	}

	// Add functions to overlap events.
	RangeCollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &ATowerAIController::AddEnemy);
	RangeCollisionMesh->OnComponentEndOverlap.AddDynamic(this, &ATowerAIController::RemoveEnemy);
}

void ATowerAIController::AddEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEnemyBase* Enemy = Cast<AEnemyBase, AActor>(OtherActor);

	if (!Enemy)
	{
		return;
	}

	AvailableTargets.AddUnique(Enemy);

	if (!World->GetTimerManager().IsTimerActive(AttackTimerHandle))
	{
		StartAttacking();
	}
}

void ATowerAIController::RemoveEnemy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AEnemyBase* Enemy = Cast<AEnemyBase, AActor>(OtherActor);

	if (!Enemy)
	{
		return;
	}

	AvailableTargets.Remove(Enemy);

	if (Enemy == Target)
	{
		Target = nullptr;
	}
}

void ATowerAIController::HandleAttack()
{
	while (!Target || Target->GetHealth() <= 0)
	{
		if (AvailableTargets.Num() == 0)
		{
			World->GetTimerManager().ClearTimer(AttackTimerHandle);

			return;
		}

		int32 LastIndex = AvailableTargets.Num() - 1;
		Target = AvailableTargets[LastIndex];
		AvailableTargets.RemoveAt(LastIndex);
	}

	ControlledTower->AttackEnemy(Target);
}

FORCEINLINE void ATowerAIController::StartAttacking()
{
	World->GetTimerManager().SetTimer(AttackTimerHandle, this, &ATowerAIController::HandleAttack, ControlledTower->GetAttackCooldown(), true);

	HandleAttack();
}
