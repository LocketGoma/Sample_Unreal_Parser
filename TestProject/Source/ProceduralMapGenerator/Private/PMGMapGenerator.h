// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//Generator / Writter / Loader // Manager

#include "EngineMinimal.h"
#include "../ProceduralMapGenerator.h"

class PMGBinaryTree;
class PMGBinaryTreeNode;
//PMG����ý���
class PMGMapGenerator
{
public:
	PMGMapGenerator(void);
	~PMGMapGenerator(void);


	//���� �ʿ� ���ڵ�
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
	

//���� ���� ���ڵ� (Generate�Ҷ� �ʿ��� ����) - �⺻�� : -1
private:
	uint32 _iMakeCount;				//�� �ִ� ����
	uint32 _iMakeHeight;				//�� ��ü ����
	uint32 _iMakeWidth;				//�� ��ü ��
	uint32 _iMakeInterval;			//�� ���� ��
	FVector _vMinPositionSize;	
	uint32 _iMaxTryExponential;		//�ִ� �ɰ� ȸ��

	bool _roomGenerateLock;

//���� Lock ���� (�����)
private:
	const uint32 _iMaxRoomCount	= 128;
	const uint32 _iMaxTryCount	= 1024;
	const uint32 _iPrecision	= 1000; //(��Ȯ��)

//���� ������ ���޿� ����
private:
	PMGBinaryTree* _roomTree;
	FArrayOfRoomData _roomArray;

};
