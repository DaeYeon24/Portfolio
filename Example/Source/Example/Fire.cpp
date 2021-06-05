// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// 컴포넌트 초기화
	fireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	// 해당 클래스 루트 컴포넌트 설정
	RootComponent = fireParticle;

	fireTime = 5;
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();
	// 타이머 설정 1초마다 AFire 클래스의 Combustion 함수를 실행하겠다.
	GetWorldTimerManager().SetTimer(fireTimerHandle, this, &AFire::Combustion, 1.0f, true);
}

// Called every frame
void AFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFire::Combustion()
{
	--fireTime;
	if (fireTime <= 0)
		OffFire();
}

void AFire::OffFire()
{
	// 타이머를 가진 핸들을 클리어함으로써 타이머 종료
	GetWorldTimerManager().ClearTimer(fireTimerHandle);
	// 파티클 디액티브 (비활성화)
	fireParticle->DeactivateSystem();
}

