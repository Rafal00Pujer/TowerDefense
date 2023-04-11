// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBase.h"
#include "EnemyBase.h"
#include "TowerDefenseGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ATowerBase::ATowerBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RangeCollisionMeshSetup();
}

// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{
	Super::BeginPlay();

	GameMode = GetWorld()->GetAuthGameMode<ATowerDefenseGameModeBase>();

	ScaleRangeCollisionMesh();
}

// Called every frame
void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (LookAtTarget)
	{
		SetActorRotation((LookAtTarget->GetActorLocation() - GetActorLocation()).Rotation());
	}
}

// Called to bind functionality to input
void ATowerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UStaticMeshComponent* ATowerBase::GetRangeCollisionMesh()
{
	return RangeCollisionMesh;
}

void ATowerBase::AttackEnemy(AEnemyBase* Target)
{
	check(Target);

	LookAtTarget = Target;

	SetActorRotation((LookAtTarget->GetActorLocation() - GetActorLocation()).Rotation());

	UParticleSystemComponent* Particle = UGameplayStatics::SpawnEmitterAttached(MuzzleFlashParticle, GetMesh(), FName(TEXT("Muzzle")));

	Target->ApplyDamage(Damage, ArmorPiercing);
}

float ATowerBase::GetAttackCooldown()
{
	return AttackCooldown;
}

FString ATowerBase::GetTowerName()
{
	return TowerName;
}

float ATowerBase::GetTowerDamage()
{
	return Damage;
}

int32 ATowerBase::GetDamageUpgradeLevel()
{
	return DamageUpgradeLevel;
}

int32 ATowerBase::GetDamageUpgradePrice()
{
	return DamageUpgradePrice;
}

float ATowerBase::GetTowerRange()
{
	return Range;
}

int32 ATowerBase::GetRangeUpgradeLevel()
{
	return RangeUpgradeLevel;
}

int32 ATowerBase::GetRangeUpgradePrice()
{
	return RangeUpgradePrice;
}

int32 ATowerBase::GetTowerArmorPiercing()
{
	return ArmorPiercing;
}

int32 ATowerBase::GetArmorPiercingUpgradeLevel()
{
	return ArmorPiercingUpgradeLevel;
}

int32 ATowerBase::GetArmorPiercingUpgradePrice()
{
	return ArmorPiercingUpgradePrice;
}

void ATowerBase::UpgradeTower(ETowerUpgrade::Type UpgradeType)
{
	switch (UpgradeType)
	{
	case ETowerUpgrade::Damage:
		if (DamageUpgradeLevel < 3 && GameMode->GetMoney() >= DamageUpgradePrice)
		{
			Damage *= DamageUpgradeFactor;
			DamageUpgradeLevel++;

			GameMode->ChangeMoney(DamageUpgradePrice * (-1));
		}
		break;

	case ETowerUpgrade::Range:
		if (RangeUpgradeLevel < 3 && GameMode->GetMoney() >= RangeUpgradePrice)
		{
			Range *= RangeUpgradeFactor;
			RangeUpgradeLevel++;

			GameMode->ChangeMoney(RangeUpgradePrice * (-1));

			ScaleRangeCollisionMesh();
		}
		break;

	case ETowerUpgrade::ArmorPiercing:
		if (ArmorPiercingUpgradeLevel < 3 && GameMode->GetMoney() >= ArmorPiercingUpgradePrice)
		{
			ArmorPiercing += ArmorPiercingUpgradeFactor;
			ArmorPiercingUpgradeLevel++;

			GameMode->ChangeMoney(ArmorPiercingUpgradePrice * (-1));
		}
	}
}

void ATowerBase::RangeCollisionMeshSetup()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> CollisionMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));

	RangeCollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RangeCollisionMesh"));
	RangeCollisionMesh->SetupAttachment(RootComponent);
	RangeCollisionMesh->SetStaticMesh(CollisionMesh.Object);
	RangeCollisionMesh->SetVisibility(false);
	RangeCollisionMesh->SetCollisionProfileName(FName(TEXT("OverlapAllDynamic")));
}

FORCEINLINE void ATowerBase::ScaleRangeCollisionMesh()
{
	float Scale = (Range * 100) / 50;
	RangeCollisionMesh->SetRelativeScale3D(FVector(Scale, Scale, 2.0));
}
