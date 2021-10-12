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
	_makeInterval = 0;
	_minPositionSize = FVector::OneVector;
	_maxTryExponential = _maxTryCount;		//최대 쪼갤 회수

	_ready = true;

	_roomTree = new PMGBinaryTree();

	_roomGenerateLock = false;

	return true;
}

void PMGMapGenerator::SetInputParametors(uint32 count, uint32 width, uint32 height, uint32 interval, uint32 tryCount)
{
	_makeCount		= count;
	_makeWidth		= width;
	_makeHeight		= height;
	_makeInterval	= interval;

	if (0 < tryCount)
	{
		_maxTryExponential = tryCount;
	}

	GenerateRoom(10);
}

void PMGMapGenerator::InputCount(uint32 count)
{
	if (_maxRoomCount < count)
	{
		_makeCount = _maxRoomCount;
	}
	else
	{
		_makeCount = count;
	}
}

void PMGMapGenerator::InputHeight(uint32 height)
{
	_makeHeight = height;
}

void PMGMapGenerator::InputWidth(uint32 width)
{
	_makeWidth = width;
}

void PMGMapGenerator::InputInterval(uint32 interval)
{
	_makeInterval = interval;
}

void PMGMapGenerator::SetTryExponential(uint32 tryCount)
{
	_maxTryExponential = tryCount;
}

void PMGMapGenerator::GetRoomArray(RoomArray& roomarray)
{
	roomarray = _roomArray;
}

bool PMGMapGenerator::GenerateRoom(uint32 depth)
{
	_ready = false;
	if (depth == 0)
	{
		return GenerateRoomData(_maxTryExponential);
	}

	return GenerateRoomData(depth);
}

bool PMGMapGenerator::GenerateRoomData(uint32 depth)
{
	RoomData roomData;
	roomData._maxVector = FVector(_makeWidth, _makeHeight, 1.0f);
	_roomTree->setRoot(new PMGBinaryTreeNode(roomData));

	return GenerateRoomNodeRecursively(0, depth,_roomTree->getRoot());
}

bool PMGMapGenerator::GenerateRoomNodeRecursively(uint32 depth, uint32 maxDepth, PMGBinaryTreeNode* nowNode)
{
	//0. 더이상 작업하지 않음.
	if (true == _roomGenerateLock)
	{
		return true;
	}

	//1. 최대 시도 (깊이) 도달
	if (maxDepth <= depth)
	{
		return false;
	}

	//2. 최대 개수 도달
	if (_makeCount <= static_cast<uint32>(_roomArray.Num()))
	{
		_roomGenerateLock = true;
		return true;
	}

	//3. 최저 크기 미만
	auto& roomData = nowNode->GetRoomData();
	if (((abs(roomData._maxVector.X - roomData._minVector.X)) < ((_minPositionSize.X+ _makeInterval) * 2)) || ((abs(roomData._maxVector.Y - roomData._minVector.Y)) < ((_minPositionSize.Y+ _makeInterval) * 2)))
	{
		return false;
	}

	//4. min > max
	if ((roomData._maxVector.X < roomData._minVector.X) || (roomData._maxVector.Y < roomData._minVector.Y))
	{
		return true;
	}
	//5. 다음 node (여기가 제일 중요)
	RoomData leftNodeData;
	RoomData rightNodeData;

	//1) 가로로 자르기 (X축 값 동일)
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
	//2) 세로로 자르기 (Y축 값 동일)
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


	if (false == GenerateRoomNodeRecursively(depth + 1, maxDepth, nowNode->GetLeftNode()))
	{
		RoomData tempRoomData = nowNode->GetLeftNode()->GetRoomData();

		tempRoomData._minVector.X += _makeInterval;
		tempRoomData._minVector.Y += _makeInterval;
		tempRoomData._maxVector.X -= _makeInterval;
		tempRoomData._maxVector.Y -= _makeInterval;

		_roomArray.Add(tempRoomData);
	}
	if (false == GenerateRoomNodeRecursively(depth + 1, maxDepth, nowNode->GetRightNode()))
	{
		RoomData tempRoomData = nowNode->GetRightNode()->GetRoomData();

		tempRoomData._minVector.X += _makeInterval;
		tempRoomData._minVector.Y += _makeInterval;
		tempRoomData._maxVector.X -= _makeInterval;
		tempRoomData._maxVector.Y -= _makeInterval;

		_roomArray.Add(tempRoomData);
	}

	return true;
}
