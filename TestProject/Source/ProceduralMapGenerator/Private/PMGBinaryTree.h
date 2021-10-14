// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
//PMG ����ý���
class PMGBinaryTreeNode;
class PMGBinaryTree
{
public:
	PMGBinaryTree(void);
	~PMGBinaryTree(void);

public:
	PMGBinaryTreeNode*	GetRoot(void);
	bool				SetRoot(PMGBinaryTreeNode* root);
	
public:
	void PreOrderTraversal(PMGBinaryTreeNode* Node);

private:
	PMGBinaryTreeNode* _root;
	
};
