// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ProceduralMapGenerator.h"

/**
 * 
 */
//PMG서브시스템
class PMGBinaryTreeNode
{
//생성자 / 소멸자
public:
	PMGBinaryTreeNode(void);
	PMGBinaryTreeNode(RoomData roomDataNode);
	~PMGBinaryTreeNode(void);

public:
	void				Initialize(void);
	void				Destroy(void);

	bool				SetLeftNode(PMGBinaryTreeNode* leftNode);
	bool				SetRightNode(PMGBinaryTreeNode* rightNode);
	bool				SetNode(PMGBinaryTreeNode* leftNode, PMGBinaryTreeNode* rightNode);
	bool				SetRoomData(RoomData& roomDataNode);

	PMGBinaryTreeNode*	GetLeftNode(void);
	PMGBinaryTreeNode*	GetRightNode(void);
	FRoomData&			GetRoomData(void);


private:
	PMGBinaryTreeNode* _leftNode;
	PMGBinaryTreeNode* _rightNode;

	//DataNode
	FRoomData			_roomDataNode;

	bool				_bReady;				//사용여부

};
