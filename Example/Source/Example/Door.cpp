// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// 컴포넌트 초기화
	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = doorMesh;

	closeTime = 3.0f;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	// 현재 회전 정보 가져오기
	originRotation = GetActorRotation();
	// 0.3초씩 타이머 설정
	GetWorldTimerManager().SetTimer(doorTimerHandle, this, &ADoor::Open, 0.03f, true);

}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	doorDeltaTime += DeltaTime;
}

void ADoor::Open()
{
	if (!bOpen)
	{
		bOpen = true;
		doorDeltaTime = 0.0f;
	}
	// 현재 로테이터 변수에 담기
	FRotator rotation = GetActorRotation();
	// 로테이터 변수에 기존 회전에 추가 회전 계산 (Lerp키워드는 최저 최대값 사이에 기준치만큼 할당해줌)
	rotation = originRotation + FRotator(0.0f, FMath::Lerp(0.0f, 90.0f, doorDeltaTime), 0.0f);
	SetActorRotation(rotation);

	if (doorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(doorTimerHandle);
		GetWorldTimerManager().SetTimer(doorTimerHandle, this, &ADoor::Close, 0.03f, true, closeTime);
	}
}

void ADoor::Close()
{
	if (bOpen)
	{
		bOpen = false;
		doorDeltaTime = 0.0f;
	}

	FRotator rotation = GetActorRotation();
	rotation = originRotation + FRotator(0.0f, FMath::Lerp(90.0f, 0.0f, doorDeltaTime), 0.0f);
	SetActorRotation(rotation);

	if (doorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(doorTimerHandle);
	}
}