// Fill out your copyright notice in the Description page of Project Settings.

#include "PMGMapGenerator.h"
#include "PMGBinaryTree.h"
#include "PMGBinaryTreeNode.h"

PMGMapGenerator::PMGMapGenerator(void) : _bReady(false), _roomTree(nullptr)
{
	Initialize();
}

PMGMapGenerator::~PMGMapGenerator(void)
{
}

bool PMGMapGenerator::Initialize(void)
{
	_iRoomCount = 0;
	_iBridgeCount = 0;

	_iMakeCount = 0;	
	_iMakeHeight = 0;
	_iMakeWidth = 0;	
	_iMakeInterval = 0;
	_vMinPositionSize = FVector::OneVector;
	_iMaxTryExponential = _iMaxTryCount;		//�ִ� �ɰ� ȸ��

	_bReady = true;

	_roomTree = new PMGBinaryTree();

	_roomGenerateLock = false;

	return true;
}

void PMGMapGenerator::SetInputParametors(uint32 iCount, uint32 iWidth, uint32 iHeight, uint32 iInterval, uint32 iTryCount)
{
	_iMakeCount		= iCount;
	_iMakeWidth		= iWidth;
	_iMakeHeight	= iHeight;
	_iMakeInterval	= iInterval;

	if (0 < iTryCount)
	{
		_iMaxTryExponential = iTryCount;
	}

	GenerateRoom(10);
}

void PMGMapGenerator::InputCount(uint32 iCount)
{
	if (_iMaxRoomCount < iCount)
	{
		_iMakeCount = _iMaxRoomCount;
	}
	else
	{
		_iMakeCount = iCount;
	}
}

void PMGMapGenerator::InputHeight(uint32 height)
{
	_iMakeHeight = height;
}

void PMGMapGenerator::InputWidth(uint32 width)
{
	_iMakeWidth = width;
}

void PMGMapGenerator::InputInterval(uint32 interval)
{
	_iMakeInterval = interval;
}

void PMGMapGenerator::SetTryExponential(uint32 tryCount)
{
	_iMaxTryExponential = tryCount;
}

void PMGMapGenerator::GetRoomArray(FArrayOfRoomData& roomarray)
{
	roomarray = _roomArray;
}

bool PMGMapGenerator::GenerateRoom(uint32 iDepth)
{
	_bReady = false;
	if (iDepth == 0)
	{
		return GenerateRoomData(_iMaxTryExponential);
	}

	return GenerateRoomData(iDepth);
}

bool PMGMapGenerator::GenerateRoomData(uint32 depth)
{
	RoomData roomData;
	roomData._vMaxVector = FVector(_iMakeWidth, _iMakeHeight, 1.0f);
	_roomTree->SetRoot(new PMGBinaryTreeNode(roomData));

	return GenerateRoomNodeRecursively(0, depth,_roomTree->GetRoot());
}

bool PMGMapGenerator::GenerateRoomNodeRecursively(uint32 iDepth, uint32 iMaxDepth, PMGBinaryTreeNode* nowNode)
{
	//0. ���̻� �۾����� ����.
	if (true == _roomGenerateLock)
	{
		return true;
	}

	//1. �ִ� �õ� (����) ����
	if (iMaxDepth <= iDepth)
	{
		return false;
	}

	//2. �ִ� ���� ����
	if (_iMakeCount <= static_cast<uint32>(_roomArray.Num()))
	{
		_roomGenerateLock = true;
		return true;
	}

	//3. ���� ũ�� �̸�
	auto& roomData = nowNode->GetRoomData();
	if (((abs(roomData._vMaxVector.X - roomData._vMinVector.X)) < ((_vMinPositionSize.X+ _iMakeInterval) * 2)) || ((abs(roomData._vMaxVector.Y - roomData._vMinVector.Y)) < ((_vMinPositionSize.Y+ _iMakeInterval) * 2)))
	{
		return false;
	}

	//4. min > max
	if ((roomData._vMaxVector.X < roomData._vMinVector.X) || (roomData._vMaxVector.Y < roomData._vMinVector.Y))
	{
		return true;
	}
	//5. ���� node (���Ⱑ ���� �߿�)
	RoomData leftNodeData;
	RoomData rightNodeData;

	//1) ���η� �ڸ��� (X�� �� ����)
	if ((abs(roomData._vMaxVector.X - roomData._vMinVector.X)) < (abs(roomData._vMaxVector.Y - roomData._vMinVector.Y)))
	{
		leftNodeData._vMinVector.X = roomData._vMinVector.X;
		leftNodeData._vMinVector.Y = roomData._vMinVector.Y;
		leftNodeData._vMaxVector.X = roomData._vMaxVector.X;
		
		rightNodeData._vMinVector.X = roomData._vMinVector.X;
		rightNodeData._vMaxVector.X = roomData._vMaxVector.X;
		rightNodeData._vMaxVector.Y = roomData._vMaxVector.Y;

		float cutHeight = (static_cast<float>(rand() % static_cast<uint32>((roomData._vMaxVector.Y - roomData._vMinVector.Y - (_vMinPositionSize.Y * 2)) * _iPrecision)) / _iPrecision) + _vMinPositionSize.Y + roomData._vMinVector.Y;

		leftNodeData._vMaxVector.Y = cutHeight;
		rightNodeData._vMinVector.Y = cutHeight;

	}
	//2) ���η� �ڸ��� (Y�� �� ����)
	else
	{
		leftNodeData._vMinVector.X = roomData._vMinVector.X;
		leftNodeData._vMinVector.Y = roomData._vMinVector.Y;
		leftNodeData._vMaxVector.Y = roomData._vMaxVector.Y;

		rightNodeData._vMinVector.Y = roomData._vMinVector.Y;
		rightNodeData._vMaxVector.Y = roomData._vMaxVector.Y;
		rightNodeData._vMaxVector.X = roomData._vMaxVector.X;


		float cutWidth = (static_cast<float>(rand() % static_cast<uint32>((roomData._vMaxVector.X - roomData._vMinVector.X - (_vMinPositionSize.X * 2)) * _iPrecision)) / _iPrecision) + _vMinPositionSize.X + roomData._vMinVector.X;

		leftNodeData._vMaxVector.X = cutWidth;
		rightNodeData._vMinVector.X = cutWidth;
	}

	nowNode->SetLeftNode(new PMGBinaryTreeNode(leftNodeData));
	nowNode->SetRightNode(new PMGBinaryTreeNode(rightNodeData));


	if (false == GenerateRoomNodeRecursively(iDepth + 1, iMaxDepth, nowNode->GetLeftNode()))
	{
		RoomData tempRoomData = nowNode->GetLeftNode()->GetRoomData();

		tempRoomData._vMinVector.X += _iMakeInterval;
		tempRoomData._vMinVector.Y += _iMakeInterval;
		tempRoomData._vMaxVector.X -= _iMakeInterval;
		tempRoomData._vMaxVector.Y -= _iMakeInterval;

		_roomArray.Add(tempRoomData);
	}
	if (false == GenerateRoomNodeRecursively(iDepth + 1, iMaxDepth, nowNode->GetRightNode()))
	{
		RoomData tempRoomData = nowNode->GetRightNode()->GetRoomData();

		tempRoomData._vMinVector.X += _iMakeInterval;
		tempRoomData._vMinVector.Y += _iMakeInterval;
		tempRoomData._vMaxVector.X -= _iMakeInterval;
		tempRoomData._vMaxVector.Y -= _iMakeInterval;

		_roomArray.Add(tempRoomData);
	}

	return true;
}
