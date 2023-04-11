// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

class UTextBlock;
class UNamedSlot;


/**
 *
 */
UCLASS()
class TOWERDEFENSE_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UMainWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	/// <summary>
	/// Shows widget on named slot side slot.
	/// </summary>
	/// <param name="UserWidget">Widget to show.</param>
	void ShowWidgetOnSideSlot(UUserWidget* UserWidget);

	/// <summary>
	/// Hides widget on named slot side slot.
	/// </summary>
	/// /// <param name="UserWidget">Widget to hide.</param>
	void HideWidgetOnSideSlot(UUserWidget* UserWidget);

	/// <summary>
	/// Shows money.
	/// </summary>
	/// <param name="Money">Money to show.</param>
	void ShowMoney(int32 Money);

	/// <summary>
	/// Shows life.
	/// </summary>
	/// <param name="Life">Life to show.</param>
	void ShowLife(int32 Life);

private:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Money text block.
		/// </summary>
		UTextBlock* MoneyText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Life text block.
		/// </summary>
		UTextBlock* LifeText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		/// <summary>
		/// Side slot.
		/// </summary>
		UNamedSlot* SideSlot;
};
