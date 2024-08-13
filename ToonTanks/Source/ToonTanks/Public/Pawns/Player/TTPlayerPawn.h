// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/TTPawn.h"
#include "TTPlayerPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOONTANKS_API ATTPlayerPawn : public ATTPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATTPlayerPawn();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	//Components
	UPROPERTY(VisibleAnywhere, Category ="Components")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, Category ="Components")
	UCameraComponent* CameraComp;
};
