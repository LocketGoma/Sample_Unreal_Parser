// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//Generator / Writter / Loader // Manager

#include "EngineMinimal.h"
#include "../ProceduralMapGenerator.h"

class PMGBinaryTree;
class PMGBinaryTreeNode;
//PMG서브시스템
class PMGMapGenerator
{
public:
	PMGMapGenerator(void);
	~PMGMapGenerator(void);


	//내부 필요 인자들
private:
	uint32 _iRoomCount;
	uint32 _iBridgeCount;
	bool _bReady;

private:
	bool Initialize();

public:
	void SetInputParametors(uint32 iCount,uint32 iWidth, uint32 iHeight, uint32 iInterval, uint32 iTryCount = 0);
	void InputCount(uint32 iCount);
	void InputWidth(uint32 iWidth);
	void InputHeight(uint32 iHeight);
	void InputInterval(uint32 iInterval);
	void SetTryExponential(uint32 iTryCount);

public:
	void GetRoomArray(FArrayOfRoomData& roomArray);
	bool GenerateRoom(uint32 iRuns);

private:
	bool GenerateRoomData(uint32 iRuns);
	bool GenerateRoomNodeRecursively(uint32 iDepth, uint32 iMaxDepth, PMGBinaryTreeNode* nowNode);
	

//내부 세팅 인자들 (Generate할때 필요한 인자) - 기본값 : -1
private:
	uint32 _iMakeCount;				//방 최대 개수
	uint32 _iMakeHeight;				//맵 전체 높이
	uint32 _iMakeWidth;				//맵 전체 폭
	uint32 _iMakeInterval;			//각 블럭당 폭
	FVector _vMinPositionSize;	
	uint32 _iMaxTryExponential;		//최대 쪼갤 회수

	bool _roomGenerateLock;

//내부 Lock 인자 (상수값)
private:
	const uint32 _iMaxRoomCount	= 128;
	const uint32 _iMaxTryCount	= 1024;
	const uint32 _iPrecision	= 1000; //(정확도)

//내부 데이터 전달용 인자
private:
	PMGBinaryTree* _roomTree;
	FArrayOfRoomData _roomArray;

};
