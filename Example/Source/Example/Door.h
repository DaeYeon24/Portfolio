// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/StaticMeshComponent.h>
#include "Door.generated.h"

UCLASS()
class EXAMPLE_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ������Ʈ ���� �ʿ��� ����� ���ʷ���Ʈ ��� ���� �ۼ�
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* doorMesh;

	UPROPERTY(EditAnywhere)
		float closeTime;

	float doorDeltaTime;

	bool bOpen;
	// Ÿ�̸� �ڵ�
	FTimerHandle doorTimerHandle;
	// �������� ����
	FRotator originRotation;

	void Open();

	void Close();
};
