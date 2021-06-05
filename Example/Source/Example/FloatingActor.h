// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class EXAMPLE_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// º¤ÅÍ ¼±¾ð
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector runingTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector floatingSpeed;
};
