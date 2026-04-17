// Fill out your copyright notice in the Description page of Project Settings.


#include "MyP38.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyP38::AMyP38()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

}

// Called when the game starts or when spawned
void AMyP38::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyP38::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector(), BoostValue);

}

// Called to bind functionality to input
void AMyP38::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UIC)
	{
		UIC->BindAction(IA_Rotate, ETriggerEvent::Triggered, this, &AMyP38::Rotate);
		UIC->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &AMyP38::Fire);
		UIC->BindAction(IA_Boost, ETriggerEvent::Triggered, this, &AMyP38::Boost);
		UIC->BindAction(IA_Boost, ETriggerEvent::Completed, this, &AMyP38::Unboost);
	}
}

void AMyP38::Rotate(const FInputActionValue& Value)
{
	FVector2D Rot = Value.Get<FVector2D>();
	Rot = Rot * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * 60.0f;

	AddActorLocalRotation(FRotator(Rot.Y, 0, Rot.X));
}

void AMyP38::Fire(const FInputActionValue& Value)
{

}

void AMyP38::Boost(const FInputActionValue& Value)
{
	BoostValue = 1.0f;
}

void AMyP38::Unboost(const FInputActionValue& Value)
{
	BoostValue = 0.5f;
}
