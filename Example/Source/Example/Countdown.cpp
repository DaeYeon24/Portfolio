// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	// tick함수를 사용하지 않겠다.
	PrimaryActorTick.bCanEverTick = false;
	//countdownText 초기화
	countdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("countdown Text"));
	countdownText->SetHorizontalAlignment(EHTA_Center);
	countdownText->SetWorldSize(150.0f);
	// 이 액터의 루트컴포넌트를 countdownText로 설정
	RootComponent = countdownText;

	countdownTime = 3;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateTimeDisplay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

void ACountdown::UpdateTimeDisplay()
{
	countdownText->SetText(FString::FromInt(FMath::Max(countdownTime, 0)));
}

void ACountdown::AdvanceTimer()
{
	--countdownTime;
	UpdateTimeDisplay();

	if (countdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ACountdown::CountdownHasFinished_Implementation()
{
	countdownText->SetText(TEXT("Go!"));
}