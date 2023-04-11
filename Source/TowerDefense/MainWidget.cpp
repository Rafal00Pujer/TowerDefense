// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/TextBlock.h"
#include "Components/NamedSlot.h"

UMainWidget::UMainWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMainWidget::ShowWidgetOnSideSlot(UUserWidget* UserWidget)
{
	check(UserWidget);

	SideSlot->AddChild(UserWidget);
}

void UMainWidget::HideWidgetOnSideSlot(UUserWidget* UserWidget)
{
	check(UserWidget);

	SideSlot->RemoveChild(UserWidget);
}

void UMainWidget::ShowMoney(int32 Money)
{
	MoneyText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Money %i$"), Money)));
}

void UMainWidget::ShowLife(int32 Life)
{
	LifeText->SetText(FText::AsCultureInvariant(FString::Printf(TEXT("Life %i"), Life)));
}
