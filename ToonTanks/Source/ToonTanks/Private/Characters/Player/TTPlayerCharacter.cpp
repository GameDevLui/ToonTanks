// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Player/TTPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATTPlayerCharacter* ATTPlayerCharacter::TTPlayer = nullptr;

// Sets default values
ATTPlayerCharacter::ATTPlayerCharacter()
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
void ATTPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATTPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATTPlayerCharacter::Move(FVector2D Value)
{
	MoveForward(Value.X);
	MoveRight(Value.Y);
}

void ATTPlayerCharacter::Look(FVector2D Value)
{
	LookUp(Value.Y);
	LookRight(Value.X);
}

void ATTPlayerCharacter::MoveForward(float Value) const
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.Y = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	TTPlayer->AddActorLocalOffset(DeltaLocation, true, nullptr, ETeleportType::None);
}

void ATTPlayerCharacter::MoveRight(float Value) const
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	TTPlayer->AddActorLocalOffset(DeltaLocation, true, nullptr, ETeleportType::None);
}

void ATTPlayerCharacter::LookUp(float Value) const
{
	TTPlayer->AddControllerPitchInput(Value);
}

void ATTPlayerCharacter::LookRight(float Value) const
{
	TTPlayer->AddControllerYawInput(Value);
}