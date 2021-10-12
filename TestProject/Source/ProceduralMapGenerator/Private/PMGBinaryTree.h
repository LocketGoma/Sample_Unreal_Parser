// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class PMGBinaryTreeNode;
class PMGBinaryTree
{
public:
	PMGBinaryTree();
	~PMGBinaryTree();

public:
	PMGBinaryTreeNode*	getRoot();
	bool				setRoot(PMGBinaryTreeNode* root);
	
public:
	void PreOrderTraversal(PMGBinaryTreeNode* Node);

private:
	PMGBinaryTreeNode* _root;
	
};
