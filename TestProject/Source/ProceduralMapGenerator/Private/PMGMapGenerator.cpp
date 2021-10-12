// Fill out your copyright notice in the Description page of Project Settings.

#include "PMGMapGenerator.h"
#include "PMGBinaryTree.h"
#include "PMGBinaryTreeNode.h"

PMGMapGenerator::PMGMapGenerator() : _ready(false), _roomTree(nullptr)
{
	Initialize();
}

PMGMapGenerator::~PMGMapGenerator()
{
}

bool PMGMapGenerator::Initialize()
{
	_roomCount = 0;
	_bridgeCount = 0;

	_makeCount = 0;	
	_makeHeight = 0;
	_makeWidth = 0;	
	_makeSize = 0;	
	_maxPositionSize = FVector::OneVector;
	_minPositionSize = FVector::OneVector;
	_maxTryExponential = _maxTryCount;		//최대 쪼갤 회수

	_ready = true;

	_roomTree = new PMGBinaryTree();

	return true;
}

void PMGMapGenerator::SetInputParametors(uint32 count, uint32 height, uint32 width, uint32 size, uint32 tryCount)
{
	_makeCount = count;
	_makeHeight = height;
	_makeWidth = width;
	_makeSize = size;
	_maxTryExponential = tryCount;

	GenerateRoom(10);
}

void PMGMapGenerator::InputCount(uint32 count)
{
	_makeCount = count;
}

void PMGMapGenerator::InputHeight(uint32 height)
{
	_makeHeight = height;
}

void PMGMapGenerator::InputWidth(uint32 width)
{
	_makeWidth = width;
}

void PMGMapGenerator::InputSize(uint32 size)
{
	_makeSize = size;
}

void PMGMapGenerator::SetTryExponential(uint32 tryCount)
{
	_maxTryExponential = tryCount;
}

void PMGMapGenerator::GetRoomArray(RoomArray& roomarray)
{
	roomarray = _roomArray;
}

bool PMGMapGenerator::GenerateRoom(uint32 runs)
{
	_ready = false;
	if (runs == 0)
	{
		return GenerateRoomData(_maxRoomCount);
	}

	return GenerateRoomData(runs);
}

bool PMGMapGenerator::GenerateRoomData(uint32 runs)
{
	RoomData roomData;
	roomData._maxVector = FVector(_makeWidth, _makeHeight, 1.0f);
	_roomTree->setRoot(new PMGBinaryTreeNode(roomData));

	return GenerateRoomNodeRecursively(0,_roomTree->getRoot());
}

bool PMGMapGenerator::GenerateRoomNodeRecursively(uint32 depth, PMGBinaryTreeNode* nowNode)
{
	//1. 최대 시도 깊이 도달
	if (4 <= depth)
	{
		return false;
	}

	//2. 최저 크기 미만
	auto& roomData = nowNode->GetRoomData();
	if (((abs(roomData._maxVector.X - roomData._minVector.X)) < (_minPositionSize.X * 2)  ) || ((abs(roomData._maxVector.Y - roomData._minVector.Y)) < (_minPositionSize.Y * 2)))
	{
		return false;
	}

	//3. min > max
	if ((roomData._maxVector.X < roomData._minVector.X) || (roomData._maxVector.Y < roomData._minVector.Y))
	{
		return true;
	}
	//4. 다음 node (여기가 제일 중요)
	RoomData leftNodeData;
	RoomData rightNodeData;

	//가로로 자르기 (X축 값 동일)
	if ((abs(roomData._maxVector.X - roomData._minVector.X)) < (abs(roomData._maxVector.Y - roomData._minVector.Y)))
	{
		leftNodeData._minVector.X = roomData._minVector.X;
		leftNodeData._minVector.Y = roomData._minVector.Y;
		leftNodeData._maxVector.X = roomData._maxVector.X;
		
		rightNodeData._minVector.X = roomData._minVector.X;
		rightNodeData._maxVector.X = roomData._maxVector.X;
		rightNodeData._maxVector.Y = roomData._maxVector.Y;

		float cutHeight = (static_cast<float>(rand() % static_cast<uint32>((roomData._maxVector.Y - roomData._minVector.Y - (_minPositionSize.Y * 2)) * _precision)) / _precision) + _minPositionSize.Y + roomData._minVector.Y;

		leftNodeData._maxVector.Y = cutHeight;
		rightNodeData._minVector.Y = cutHeight;

	}
	//세로로 자르기 (Y축 값 동일)
	else
	{
		leftNodeData._minVector.X = roomData._minVector.X;
		leftNodeData._minVector.Y = roomData._minVector.Y;
		leftNodeData._maxVector.Y = roomData._maxVector.Y;

		rightNodeData._minVector.Y = roomData._minVector.Y;
		rightNodeData._maxVector.Y = roomData._maxVector.Y;
		rightNodeData._maxVector.X = roomData._maxVector.X;


		float cutWidth = (static_cast<float>(rand() % static_cast<uint32>((roomData._maxVector.X - roomData._minVector.X - (_minPositionSize.X * 2)) * _precision)) / _precision) + _minPositionSize.X + roomData._minVector.X;

		leftNodeData._maxVector.X = cutWidth;
		rightNodeData._minVector.X = cutWidth;
	}

	nowNode->SetLeftNode(new PMGBinaryTreeNode(leftNodeData));
	nowNode->SetRightNode(new PMGBinaryTreeNode(rightNodeData));


	if (false == GenerateRoomNodeRecursively(depth + 1, nowNode->GetLeftNode()))
	{
		_roomArray.Add(nowNode->GetLeftNode()->GetRoomData());		
	}
	if (false == GenerateRoomNodeRecursively(depth + 1, nowNode->GetRightNode()))
	{
		_roomArray.Add(nowNode->GetRightNode()->GetRoomData());		
	}

	return true;
}
