// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Enemy/TTEnemyPawn.h"


// Sets default values
ATTEnemyPawn::ATTEnemyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATTEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATTEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

