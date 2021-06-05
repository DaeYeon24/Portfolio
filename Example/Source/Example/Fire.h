// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Particles/ParticleSystemComponent.h>
#include "Fire.generated.h"
// ��ó���⸦ ����Ҷ��� �׻� �ش� Ŭ���� ���ʷ���Ʈ ������� ���� �ۼ��� ��

UCLASS()
class EXAMPLE_API AFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//<Engine/Classes/Particles/ParticleSystemComponent.h> ���
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* fireParticle;

	UPROPERTY(EditAnywhere)
		int8 fireTime;
	// Ÿ�̸� �ڵ�
	FTimerHandle fireTimerHandle;

	void Combustion();

	UFUNCTION(BlueprintCallable)
		void OffFire();
};
