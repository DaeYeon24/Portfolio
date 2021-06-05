// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Particles/ParticleSystemComponent.h>
#include "Fire.generated.h"
// 전처리기를 사용할때는 항상 해당 클래스 제너레이트 헤더파일 위에 작성할 것

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

	//<Engine/Classes/Particles/ParticleSystemComponent.h> 헤더
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* fireParticle;

	UPROPERTY(EditAnywhere)
		int8 fireTime;
	// 타이머 핸들
	FTimerHandle fireTimerHandle;

	void Combustion();

	UFUNCTION(BlueprintCallable)
		void OffFire();
};
