// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ProceduralMapGenerator.h"

/**
 * 
 */
class PMGBinaryTreeNode
{
//생성자 / 소멸자
public:
	PMGBinaryTreeNode(void);
	PMGBinaryTreeNode(RoomData roomData);
	~PMGBinaryTreeNode(void);

public:
	bool				Initialize(void);
	bool				Destroy(void);

	bool				SetLeftNode(PMGBinaryTreeNode* node);
	bool				SetRightNode(PMGBinaryTreeNode* node);
	bool				SetNode(PMGBinaryTreeNode* left, PMGBinaryTreeNode* right);
	bool				SetRoomData(RoomData& data);

	//C2662
	PMGBinaryTreeNode*	GetLeftNode(void);
	PMGBinaryTreeNode*	GetRightNode(void);
	RoomData&			GetRoomData(void);


private:
	PMGBinaryTreeNode* _leftNode;
	PMGBinaryTreeNode* _rightNode;

	//DataNode
	RoomData			_roomData;

	bool				_ready;				//사용여부

};
