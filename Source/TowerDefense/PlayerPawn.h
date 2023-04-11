// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UCameraComponent;

UCLASS()
class TOWERDEFENSE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;

	UPROPERTY()
		UWorld* World;

	UPROPERTY(EditAnywhere)
		float MovementSpeed = 100;

	UPROPERTY(EditAnywhere)
		FRotator CameraAngle;

	FVector MoveDirection;

	UFUNCTION()
		void MoveForwardBackward(float Value);

	UFUNCTION()
		void MoveLeftRight(float Value);

	void HandleMovement();
};
