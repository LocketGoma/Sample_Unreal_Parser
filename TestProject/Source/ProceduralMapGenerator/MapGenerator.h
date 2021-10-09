// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

//전방선언
class UStaticMeshComponent;

UCLASS()
class PROCEDURALMAPGENERATOR_API AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



//내부 필요 인자들
private:
	uint32 _roomCount;
	uint32 _bridgeCount;
	TArray<UStaticMeshComponent> _roomArray;			//생성된 Room Array

//내부 세팅 인자들 (Generate할때 필요한 인자) - 기본값 : -1
private:
	int32 _makeCount;
	int32 _makeHeight;
	int32 _makeWidth;
	int32 _makeSize;

//내부 Lock 인자 (상수값)
	const int32 _maxRoomCount = 128;


};
