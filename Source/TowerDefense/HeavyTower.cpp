// Fill out your copyright notice in the Description page of Project Settings.


#include "HeavyTower.h"
#include "EnemyBase.h"

AHeavyTower::AHeavyTower()
{
	ExplosiveCollisionMeshSetup();
}

void AHeavyTower::BeginPlay()
{
	Super::BeginPlay();

	ScaleExplosiveCollisionMesh();
}

void AHeavyTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHeavyTower::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AHeavyTower::AttackEnemy(AEnemyBase* Target)
{
	check(Target);

	Super::AttackEnemy(Target);

	ExplosiveCollisionMesh->SetWorldLocation(Target->GetActorLocation());

	TArray<AActor*> Enemies;
	ExplosiveCollisionMesh->GetOverlappingActors(Enemies, TSubclassOf<AActor>(AEnemyBase::StaticClass()));

	for (AActor* Actor : Enemies)
	{
		AEnemyBase* Enemy = Cast<AEnemyBase, AActor>(Actor);

		if (Enemy == Target)
		{
			break;
		}

		Enemy->ApplyDamage(ExplosiveDamage);
	}

	ExplosiveCollisionMesh->SetWorldLocation(GetActorLocation());
}

void AHeavyTower::ExplosiveCollisionMeshSetup()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> CollisionMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));

	ExplosiveCollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ExplosiveCollisionMesh"));
	ExplosiveCollisionMesh->SetupAttachment(RootComponent);
	ExplosiveCollisionMesh->SetStaticMesh(CollisionMesh.Object);
	ExplosiveCollisionMesh->SetVisibility(false);
	ExplosiveCollisionMesh->SetCollisionProfileName(FName(TEXT("OverlapAllDynamic")));
}

void AHeavyTower::ScaleExplosiveCollisionMesh()
{
	float Scale = (ExplosiveRange * 100) / 50;
	ExplosiveCollisionMesh->SetRelativeScale3D(FVector(Scale, Scale, 2.0));
}