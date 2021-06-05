// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/TextRenderComponent.h>
#include "Countdown.generated.h"

UCLASS()
class EXAMPLE_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// 타이머 시간 변수
	UPROPERTY(EditAnywhere)
	int32 countdownTime;

	UTextRenderComponent* countdownText;

	void UpdateTimeDisplay();

	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;
};
