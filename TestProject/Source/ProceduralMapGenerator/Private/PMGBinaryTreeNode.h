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
	PMGBinaryTreeNode();
	PMGBinaryTreeNode(RoomData roomData);
	~PMGBinaryTreeNode();

public:
	bool				Initialize();
	bool				Destroy();

	bool				SetLeftNode(PMGBinaryTreeNode* node);
	bool				SetRightNode(PMGBinaryTreeNode* node);
	bool				SetNode(PMGBinaryTreeNode* left, PMGBinaryTreeNode* right);
	bool				SetRoomData(RoomData& data);

	//C2662
	PMGBinaryTreeNode*	GetLeftNode();
	PMGBinaryTreeNode*	GetRightNode();
	RoomData&			GetRoomData();


private:
	PMGBinaryTreeNode* _leftNode;
	PMGBinaryTreeNode* _rightNode;

	//DataNode
	RoomData			_roomData;

	bool				_ready;				//사용여부

};
