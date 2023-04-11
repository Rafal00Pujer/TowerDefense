// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Camera\CameraComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RootComponent = Camera;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	SetActorRotation(CameraAngle);
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HandleMovement();
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForwardBackward"), this, &APlayerPawn::MoveForwardBackward);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &APlayerPawn::MoveLeftRight);
}

void APlayerPawn::MoveForwardBackward(float Value)
{
	MoveDirection.X = Value;
}

void APlayerPawn::MoveLeftRight(float Value)
{
	MoveDirection.Y = Value;
}

void APlayerPawn::HandleMovement()
{
	MoveDirection.Normalize();

	MoveDirection *= MovementSpeed * World->GetDeltaSeconds();

	AddActorWorldOffset(MoveDirection);
}

