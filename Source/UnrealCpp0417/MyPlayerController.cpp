// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	//로컬 플레이어 컨트롤러가 없으면 리턴
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
}
