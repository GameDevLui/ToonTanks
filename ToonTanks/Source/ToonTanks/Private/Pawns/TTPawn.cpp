// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/TTPawn.h"

#include "Components/BoxComponent.h"

// Sets default values
ATTPawn::ATTPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Component Constructors
	BoxComp = CreateDefaultSubobject<UBoxComponent>("Capsule Collider");
	RootComponent = BoxComp;

	PawnBodyComp = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	PawnBodyComp->SetupAttachment(BoxComp);
	PawnTurretComp = CreateDefaultSubobject<UStaticMeshComponent>("Turret");
	PawnTurretComp->SetupAttachment(PawnBodyComp);

	FiringPointComp = CreateDefaultSubobject<USceneComponent>("Firing Point");
	FiringPointComp->SetupAttachment(PawnTurretComp);

}

// Called when the game starts or when spawned
void ATTPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATTPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

