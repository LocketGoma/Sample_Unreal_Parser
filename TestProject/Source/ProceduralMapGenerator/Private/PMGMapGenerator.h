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


	//���� �ʿ� ���ڵ�
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
	

//���� ���� ���ڵ� (Generate�Ҷ� �ʿ��� ����) - �⺻�� : -1
private:
	uint32 _makeCount;				//�� �ִ� ����
	uint32 _makeHeight;				//�� ��ü ����
	uint32 _makeWidth;				//�� ��ü ��
	uint32 _makeSize;				//�� ���� ��
	FVector _maxPositionSize;
	FVector _minPositionSize;
	uint32 _maxTryExponential;		//�ִ� �ɰ� ȸ��

//���� Lock ���� (�����)
private:
	const uint32 _maxRoomCount = 128;
	const uint32 _maxTryCount = 1024;
	const uint32 _precision = 1000; //(��Ȯ��)

//���� ������ ���޿� ����
private:
	PMGBinaryTree* _roomTree;
	RoomArray _roomArray;

};
