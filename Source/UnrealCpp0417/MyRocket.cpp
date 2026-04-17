// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRocket.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyRocket::AMyRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(32.0f, 8.0f, 8.0f));

	Rocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rocket"));
	Rocket->SetupAttachment(Box);
	Rocket->SetRelativeRotation(FRotator(-90.0f, 0, 0));

	ProgectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProgectileMovement"));
	ProgectileMovement->InitialSpeed = 1000.0f;
	ProgectileMovement->MaxSpeed = 1000.0f;
	ProgectileMovement->ProjectileGravityScale = 0.0f;
	ProgectileMovement->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void AMyRocket::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(3.0f);

	OnActorBeginOverlap.AddDynamic(this, &AMyRocket::ProcessActorBeginOverlap);
}

// Called every frame
void AMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyRocket::ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("ProcessActorBeginOverlap 실행됨"));

	Destroy();
}


