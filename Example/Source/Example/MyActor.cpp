// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 틱 함수를 사용할건지 설정
	PrimaryActorTick.bCanEverTick = true;

	totalDamage = 200;
	damageTimeInSeconds = 1.0f;
	CharacterName = TEXT("제드");
	attackable = true;
	str = TEXT("test");
}

void AMyActor::CallFromCpp_Implementation()
{
	str.Append(TEXT("_Implementation"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	CallFromCpp();
	//UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Log, TEXT("Tick"));
}

void AMyActor::Function()
{

}

void AMyActor::CalculateDPS()
{
	damagePerSecond = totalDamage / damageTimeInSeconds;
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDPS();
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent)
{
	CalculateDPS();
	Super::PostEditChangeProperty(propertyChangedEvent);
}
