// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Player/TTPlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

ATTPlayerPawn* ATTPlayerPawn::TTPlayer = nullptr;

// Sets default values
ATTPlayerPawn::ATTPlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TTPlayer = this;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Camera Spring Arm");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Player Camera");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ATTPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATTPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATTPlayerPawn::Move(FVector2D Value)
{
	MoveForward(Value.X);
	MoveRight(Value.Y);
}

void ATTPlayerPawn::Look(FVector2D Value)
{
	LookUp(Value.Y);
	LookRight(Value.X);
}

void ATTPlayerPawn::MoveForward(float Value) const
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.Y = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	TTPlayer->AddActorLocalOffset(DeltaLocation, true, nullptr, ETeleportType::None);
}

void ATTPlayerPawn::MoveRight(float Value) const
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	TTPlayer->AddActorLocalOffset(DeltaLocation, true, nullptr, ETeleportType::None);
}

void ATTPlayerPawn::LookUp(float Value) const
{
	TTPlayer->AddControllerPitchInput(Value);
}

void ATTPlayerPawn::LookRight(float Value) const
{
	TTPlayer->AddControllerYawInput(Value);
}