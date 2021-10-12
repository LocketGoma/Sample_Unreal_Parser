// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//Generator / Writter / Loader // Manager

#include "EngineMinimal.h"
#include "../ProceduralMapGenerator.h"

class PMGBinaryTree;
class PMGBinaryTreeNode;

class PMGMapGenerator
{
public:
	PMGMapGenerator();
	~PMGMapGenerator();


	//내부 필요 인자들
private:
	uint32 _roomCount;
	uint32 _bridgeCount;
	bool _ready;

private:
	bool Initialize();

public:
	void SetInputParametors(uint32 count, uint32 height, uint32 width, uint32 size, uint32 tryCount);
	void InputCount(uint32 count);
	void InputHeight(uint32 height);
	void InputWidth(uint32 width);
	void InputSize(uint32 size);
	void SetTryExponential(uint32 tryCount);

public:
	void GetRoomArray(RoomArray& roomarray);
	bool GenerateRoom(uint32 runs);

private:
	bool GenerateRoomData(uint32 runs);
	bool GenerateRoomNodeRecursively(uint32 depth, PMGBinaryTreeNode* nowNode);
	

//내부 세팅 인자들 (Generate할때 필요한 인자) - 기본값 : -1
private:
	uint32 _makeCount;				//방 최대 개수
	uint32 _makeHeight;				//맵 전체 높이
	uint32 _makeWidth;				//맵 전체 폭
	uint32 _makeSize;				//각 블럭당 폭
	FVector _maxPositionSize;
	FVector _minPositionSize;
	uint32 _maxTryExponential;		//최대 쪼갤 회수

//내부 Lock 인자 (상수값)
private:
	const uint32 _maxRoomCount = 128;
	const uint32 _maxTryCount = 1024;
	const uint32 _precision = 1000; //(정확도)

//내부 데이터 전달용 인자
private:
	PMGBinaryTree* _roomTree;
	RoomArray _roomArray;

};
