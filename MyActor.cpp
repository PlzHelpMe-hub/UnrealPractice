// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "VisualLoggerExtension.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TotalDamage = 200;
	DamageTimeInSeconds = 1.0f;
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

void AMyActor::CalculateValues()
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();

	CalculateValues();
}

float AMyActor::FunctionTest01()
{
	return 1.0f;
}

float AMyActor::FunctionTest02(float FValue)
{
	return 0.0f + FValue;
}


#if WITH_EDITOR
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) //아래 코드는 에디터에서 변해가는 파생된 값의 계산에 필요한 후크 추가를 나타냄
{
	CalculateValues();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif