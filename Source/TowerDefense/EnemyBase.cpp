// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnemyAIController.h"
#include "EnemyWidgetBase.h"
#include "TowerDefenseGameModeBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	World = GetWorld();

	CharacterMovementComp = GetCharacterMovement();

	Widget = Cast<UEnemyWidgetBase, UUserWidget>(WidgetComponent->GetUserWidgetObject());

	Widget->UpdateHealthBar(1.0);
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float AEnemyBase::GetHealth()
{
	return CurrentHealth;
}

void AEnemyBase::ApplyDamage(float Damge, int32 ArmorPiercing)
{
	int32 DamageReduction = Armor - ArmorPiercing;

	if (DamageReduction < 0)
	{
		DamageReduction = 0;
	}

	Damge -= DamageReduction;

	if (Damge <= 0)
	{
		Damge = 1;
	}

	CurrentHealth -= Damge;

	if (CurrentHealth <= 0)
	{
		ATowerDefenseGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ATowerDefenseGameModeBase>();

		GameMode->ChangeMoney(5);

		Destroy();
	}

	Widget->UpdateHealthBar(CurrentHealth / MaxHealth);
}

void AEnemyBase::ApplySlowEffect(float Percent, float Duration)
{
	if (World->GetTimerManager().IsTimerActive(SlowEffectTimer))
	{
		CharacterMovementComp->MaxWalkSpeed += SlowEffectValue;
	}

	SlowEffectValue = CharacterMovementComp->MaxWalkSpeed * Percent;
	CharacterMovementComp->MaxWalkSpeed -= SlowEffectValue;

	World->GetTimerManager().SetTimer(SlowEffectTimer, this, &AEnemyBase::ClearSlowEffect, Duration);
}

void AEnemyBase::ClearSlowEffect()
{
	CharacterMovementComp->MaxWalkSpeed += SlowEffectValue;
	SlowEffectValue = 0;
}