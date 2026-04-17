// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyP38.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyP38::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();

	//리플렉션(ReFlection)
	//실행 중에 클래스의 정보를 가져오는 기능
	//C++에는 이 기능이 없음
	//근데 언리얼에서는 가능함 -> 왜냐?
	//매크로로 코드를 만들기 때문
	//내가 만든 Test변수 위에 UPROPERTY() 넣으면
	//실행중에 내가만든 Test변수 정보 가지고 오기 가능
	//Editor 작업을 하기 위해서 필요
	for (TFieldIterator<FProperty> Iter(GetClass()); Iter; ++Iter)
	{
		//Property -> 속성 -> 멤버변수

		auto Value = *Iter;
		//UE_LOG(LogTemp, Warning,TEXT("Property %s"), *Value->GetName());
	}


	for (TFieldIterator<UFunction> Iter(GetClass()); Iter; ++Iter)
	{

	}
}
