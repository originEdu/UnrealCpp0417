// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <EnhancedInputLibrary.h>
#include "InputAction.h"
#include "MyP38.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UFloatingPawnMovement;
class UArrowComponent;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class AMyRocket;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FCountSignature, AMyP38, OnUpdateCount);

UCLASS()
class UNREALCPP0417_API AMyP38 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyP38();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//컴포넌트 관련
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UFloatingPawnMovement> Movement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TSubclassOf<AMyRocket> RocketTemplate;

	//Input 관련
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Rotate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Fire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Boost;

	void Rotate(const FInputActionValue& Value);

	void Fire(const FInputActionValue& Value);

	void Boost(const FInputActionValue& Value);

	void Unboost(const FInputActionValue& Value);

	float BoostValue = 0.5f;

	UPROPERTY(BlueprintAssignable, Category = "UMG")
	FCountSignature OnUpdateCount;

	UFUNCTION(BlueprintImplementableEvent)
	void CallCPPTOExcuteBP();

	UFUNCTION(BlueprintNativeEvent)
	void CallDefaultCPPTOExcuteBP();
	void CallDefaultCPPTOExcuteBP_Implementation();

	UFUNCTION(BlueprintCallable)
	void SupportBlueprint();
};
