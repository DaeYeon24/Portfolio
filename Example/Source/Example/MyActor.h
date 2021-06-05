// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class EXAMPLE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	// 생성자
	AMyActor();

	// 유프로퍼티로 에디터에 노출, 블루프린트 활용 가능
	// EditAnywhere  = 에디터 노출
	// BlueprintReadWrite = 블루프린트에서 활용 (리드, 라이트로 읽기,쓰기 권한 부여)
	// VisibleAnywhere = 모니터링만 가능 값 변경 불가
	// Category = 카테고리 지정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	int32 totalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float damageTimeInSeconds;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
	float damagePerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool attackable;

	// test
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		FString str;
	// 블루프린트에서 CPP로 받아오기
	UFUNCTION(BlueprintNativeEvent, Category = "Damage")
	void CallFromCpp();
	// 디폴트 함수
	virtual void CallFromCpp_Implementation();

protected:
	// Called when the game starts or when spawned
	// 게임시작시 최초 1회 실행 유니티의 Start함수와 비슷
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// 유니티의 Update함수
	virtual void Tick(float DeltaTime) override;
	
	void Function();

	// 블루프린트에 활용하려면 UFUNCTION 사용
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void CalculateDPS();

	virtual void PostInitProperties() override;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent) override;
};
