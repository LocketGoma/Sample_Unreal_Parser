// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "../ProceduralMapGenerator.h"
#include "PMGMapManager.generated.h"

//���漱��
class UStaticMeshComponent;
class AMapGenerator;

UCLASS()
class PROCEDURALMAPGENERATOR_API APMGMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APMGMapManager();

private:
	bool Initialize();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	//const RoomArray& GetRoomArray();
	void GetRoomArray(RoomArray& roomarray);

//���� ���۰���
public:
	bool SetInputParametors(uint32 count, uint32 height, uint32 width, uint32 size);

//Map Make Part
public:
	void MakeRoomFromGenerator();		//���õ� ���׷����ͷ� ����
	void MakeRoomFromJson();			//�о���� Json���Ͽ��� ����


	void ResetRoom();					//�ʱ�ȭ

//Generator Machine
private:
	//MapGenerator* roomGenerator;

};
