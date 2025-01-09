// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBC_5_API AMyActor : public AActor
{
	GENERATED_BODY()

private:
	FVector2D	start;		// 위치
	int32		evCnt;		// 이벤트 발생횟수
	float		totDist;	// 총 이동 거리
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void move();
	int32_t step();
};
