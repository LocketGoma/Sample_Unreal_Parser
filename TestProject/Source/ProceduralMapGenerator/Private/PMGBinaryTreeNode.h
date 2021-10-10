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
	~PMGBinaryTreeNode();

public:
	bool						initialize();
	bool						destroy();

	bool						setLeftNode(PMGBinaryTreeNode* node);
	bool						setRightNode(PMGBinaryTreeNode* node);
	bool						setNode(PMGBinaryTreeNode* left, PMGBinaryTreeNode* right);
	bool						setRoomData(RoomData& data);

	//C2662
	PMGBinaryTreeNode*	getLeftNode();
	PMGBinaryTreeNode*	getRightNode();
	RoomData&			getRoomData();


private:
	PMGBinaryTreeNode* _leftNode;
	PMGBinaryTreeNode* _rightNode;

	//DataNode
	RoomData			_roomData;

	bool				_ready;				//사용여부

};
