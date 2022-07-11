// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		int32 TotalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float DamageTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitProperties();

	UFUNCTION(BlueprintCallable, Category = "Damage") //C++ �ڵ带 �������Ʈ�� ȣ��
	virtual void CalculateValues();

	//UFUNCTION(BlueprintImplementableEvent, Category = "Damage") //C++ �ڵ忡�� �������Ʈ�� ���ǵ� �Լ��� ȣ��
	//void CalledFromCpp();
	//UFUNCTION(BlueprintNativeEvent, Category = "Damage") //�������Ʈ�� �޼��带 ��� �� �ֵ��� �ϸ鼭�� C++ �⺻ ������ ����

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);
};
