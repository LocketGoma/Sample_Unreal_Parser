// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "MapGenerator.generated.h"

//���漱��
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



//���� �ʿ� ���ڵ�
private:
	uint32 _roomCount;
	uint32 _bridgeCount;
	TArray<UStaticMeshComponent> _roomArray;			//������ Room Array

//���� ���� ���ڵ� (Generate�Ҷ� �ʿ��� ����) - �⺻�� : -1
private:
	int32 _makeCount;
	int32 _makeHeight;
	int32 _makeWidth;
	int32 _makeSize;

//���� Lock ���� (�����)
	const int32 _maxRoomCount = 128;


};
