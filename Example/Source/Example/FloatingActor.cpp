// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// ���� �ʱ�ȭ
	floatingSpeed = FVector(1.0f, 1.0f, 1.0f);
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
	// string
	FString str = TEXT("Hi");
	// bool
	bool isBool = true;
	// int
	int hp = 100;
	// float
	float speed = 5.0f;
	// �α� ��� �ڷ��� ��������
	UE_LOG(LogTemp, Warning, TEXT("str = %s, bool = %s, int = %d, float = %f"), *str, isBool ? TEXT("true") : TEXT("false"), hp, speed);
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// ���� ��ġ �޾ƿ���
	FVector newLocation = GetActorLocation();
	// �� ���� ���� ���
	float DeltaX = (FMath::Sin(runingTime.X + DeltaTime * floatingSpeed.X) - FMath::Sin(runingTime.X));
	float DeltaY = (FMath::Sin(runingTime.Y + DeltaTime * floatingSpeed.Y) - FMath::Sin(runingTime.Y));
	float DeltaZ = (FMath::Sin(runingTime.Z + DeltaTime * floatingSpeed.Z) - FMath::Sin(runingTime.Z));
	// ��ġ�� ����
	newLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.0f;
	// ����Ÿ��
	runingTime += DeltaTime * floatingSpeed;
	// ������ ��ġ ����
	SetActorLocation(newLocation);
}

