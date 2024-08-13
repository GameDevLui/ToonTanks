// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/TTCharacter.h"
#include "TTPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOONTANKS_API ATTPlayerCharacter : public ATTCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATTPlayerCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	static ATTPlayerCharacter* TTPlayer;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	//Components
	UPROPERTY(VisibleAnywhere, Category ="Components")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, Category ="Components")
	UCameraComponent* CameraComp;

	//Properties
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 100.0f;
	
	//Functions
	UFUNCTION(BlueprintCallable, Category = "Input Control")
	void Move(FVector2D Value);
	UFUNCTION(BlueprintCallable, Category = "Input Control")
	void Look(FVector2D Value);

	//Private Functions
	void MoveForward(float Value) const;
	void MoveRight(float Value) const;
	void LookUp(float Value) const;
	void LookRight(float Value) const;
};
