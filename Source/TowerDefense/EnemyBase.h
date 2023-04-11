// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

class UWidgetComponent;
class UEnemyWidgetBase;
class UCharacterMovementComponent;

UCLASS()
class TOWERDEFENSE_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/// <summary>
	/// Gets Health of this enemy.
	/// </summary>
	/// <returns>Health of this enemy.</returns>
	float GetHealth();

	/// <summary>
	/// Applies damage to this enemy.
	/// </summary>
	/// <param name="Damge">Amount of damage to apply.</param>
	/// <param name="ArmorPiercing">Amount of armor piercing to reduce armor.</param>
	void ApplyDamage(float Damge, int32 ArmorPiercing = 0);

	/// <summary>
	/// Applies slow effect.
	/// </summary>
	/// <param name="Percent">Percentage by which to reduce the movement speed.</param>
	/// <param name="Duration">Duration of slow effect. In seconds.</param>
	void ApplySlowEffect(float Percent, float Duration);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		/// <summary>
		/// Widget of this enemy.
		/// </summary>
		UWidgetComponent* WidgetComponent;

	UPROPERTY()
		/// <summary>
		/// Quick access to enemy widget.
		/// </summary>
		UEnemyWidgetBase* Widget;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// Armor of this enemy.
		/// </summary>
		int32 Armor = 0;

	UPROPERTY(EditAnywhere)
		/// <summary>
		/// MaxHealth of this enemy.
		/// </summary>
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		/// <summary>
		/// CurrentHealth of this enemy.
		/// </summary>
		float CurrentHealth;

	UPROPERTY()
		/// <summary>
		/// Quick access to world.
		/// </summary>
		UWorld* World;

	UPROPERTY()
		/// <summary>
		/// Quick access to character movement component.
		/// </summary>
		UCharacterMovementComponent* CharacterMovementComp;

	UPROPERTY()
		/// <summary>
		/// Slow effect timer.
		/// </summary>
		FTimerHandle SlowEffectTimer;

	UPROPERTY()
		/// <summary>
		/// Value by wich speed was reduced.
		/// </summary>
		float SlowEffectValue;

	UFUNCTION()
		/// <summary>
		/// Clears slow effect.
		/// </summary>
		void ClearSlowEffect();
};
