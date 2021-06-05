// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// ������Ʈ �ʱ�ȭ
	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = doorMesh;

	closeTime = 3.0f;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	// ���� ȸ�� ���� ��������
	originRotation = GetActorRotation();
	// 0.3�ʾ� Ÿ�̸� ����
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
	// ���� �������� ������ ���
	FRotator rotation = GetActorRotation();
	// �������� ������ ���� ȸ���� �߰� ȸ�� ��� (LerpŰ����� ���� �ִ밪 ���̿� ����ġ��ŭ �Ҵ�����)
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