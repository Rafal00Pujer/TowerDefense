// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyWidgetBase.generated.h"

class UProgressBar;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API UEnemyWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UEnemyWidgetBase(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	/// <summary>
	/// Updates health bar.
	/// </summary>
	/// <param name="Percent">Fill precent. 0 is 0% 1 is 100%</param>
	void UpdateHealthBar(float Percent);

private:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Health bar.
		/// </summary>
		UProgressBar* ProgressBar_500;
};
