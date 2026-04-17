// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "MyP38.h"

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	//로컬 플레이어 컨트롤러가 없으면 리턴
	//나중에 서버를 만들면 플레이어 컨트롤러가 여러개 생긴다
	//내 자신의 컨트롤러가 아니면 동작안하게끔
	//네트워크에 사용할 코드임
	if (!IsLocalPlayerController())
	{
		return;
	}

	//문서에서 복붙한 내용
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMapping)
			{
				InputSystem->AddMappingContext(InputMapping, 0);
			}
		}
	}

	//Get SubSystem, 향상된 입력도 서브 시스템임, 입력 장치는 하나만 있다
	//서브시스템 가지고 오는 코드
	ULocalPlayer* LocalPlayer2 = GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* InputSystem2 =
		LocalPlayer2->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	
	//UEnhancedInputLocalPlayerSubsystem -> ULocalPlayerSubsystem을 상속함
	//고로 싱글톤임
	//InputSystem2->ClearAllMappings(); // 매핑 다 지워
	//for (const auto& Context : InputMappings)
	//{
	//	InputSystem2->AddMappingContext(Context, 0);
	//}
	//
	//언리얼은 서브 시스템이라고해서 자동 싱글톤을 지원해줌
	//향상된 입렵도 서브 시스템이다


	//SorftTest.LoadSynchronous(); 동기
	//SorftTest.LoadAsync(); 비동기


	AMyP38* MyPawn = Cast<AMyP38>(pawn);
	if (MyPawn)
	{
		MyPawn->OnUpdateCount.RemoveAll(this);
		MyPawn->OnUpdateCount.AddDynamic(this, &AMyPlayerController::DisplayCount);
	}
}

void AMyPlayerController::DisplayCount()
{
	UE_LOG(LogTemp, Warning,TEXT("DisplayCount 호출됨"));
}
