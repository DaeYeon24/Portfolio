// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// ������Ʈ �ʱ�ȭ
	fireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	// �ش� Ŭ���� ��Ʈ ������Ʈ ����
	RootComponent = fireParticle;

	fireTime = 5;
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();
	// Ÿ�̸� ���� 1�ʸ��� AFire Ŭ������ Combustion �Լ��� �����ϰڴ�.
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
	// Ÿ�̸Ӹ� ���� �ڵ��� Ŭ���������ν� Ÿ�̸� ����
	GetWorldTimerManager().ClearTimer(fireTimerHandle);
	// ��ƼŬ ���Ƽ�� (��Ȱ��ȭ)
	fireParticle->DeactivateSystem();
}

