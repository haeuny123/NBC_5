// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 이동 거리 계산
float AMyActor::distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

// (0, 0)부터 10회 움직이면서 좌표 출력
void AMyActor::move()
{
	start = FVector2D(0, 0);
	FVector2D current = FVector2D(start.X, start.Y);

	for (int i = 0; i < 10; i++)
	{
		FVector2D before = FVector2D(current.X, current.Y);
		current.X += step();
		current.Y += step();

		float curDist = distance(current, before);

		UE_LOG(LogTemp, Warning, TEXT("%d회 이동 현재 좌표 (%d, %d)"), i + 1, current.X, current.Y);
		UE_LOG(LogTemp, Warning, TEXT("%d회 이동 거리: %f"), i + 1, curDist);

		totDist += curDist;

		createEvent();
	}

	UE_LOG(LogTemp, Warning, TEXT("총 이동 거리: %f"), totDist);
	UE_LOG(LogTemp, Warning, TEXT("이벤트 발생횟수: %d"), evCnt);
}

// x좌표 y좌표 각각 이동할 거리
int32_t AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

// 이벤트 발생 확률 (50%)
int32 AMyActor::createEvent()
{
	if (step() == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		evCnt++;
	}

	return evCnt;
}
