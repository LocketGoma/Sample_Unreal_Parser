// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "../ProceduralMapGenerator.h"
#include "PMGMapManager.generated.h"

//전방선언
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

//인자 조작관련
public:
	bool SetInputParametors(uint32 count, uint32 height, uint32 width, uint32 size);

//Map Make Part
public:
	void MakeRoomFromGenerator();		//세팅된 제네레이터로 생성
	void MakeRoomFromJson();			//읽어들인 Json파일에서 생성


	void ResetRoom();					//초기화

//Generator Machine
private:
	//MapGenerator* roomGenerator;

};
