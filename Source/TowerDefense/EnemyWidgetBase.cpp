// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWidgetBase.h"
#include "Components/ProgressBar.h"

UEnemyWidgetBase::UEnemyWidgetBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UEnemyWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void UEnemyWidgetBase::UpdateHealthBar(float Percent)
{
	ProgressBar_500->SetPercent(Percent);
}
