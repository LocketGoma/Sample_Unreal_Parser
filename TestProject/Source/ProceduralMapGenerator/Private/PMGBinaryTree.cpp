// Fill out your copyright notice in the Description page of Project Settings.

#include "PMGBinaryTree.h"
#include "PMGBinaryTreeNode.h"

PMGBinaryTree::PMGBinaryTree(void)
{
}

PMGBinaryTree::~PMGBinaryTree(void)
{
	_root->Destroy(void);
	delete _root;
}

PMGBinaryTreeNode* PMGBinaryTree::getRoot(void)
{
	return _root;
}

bool PMGBinaryTree::setRoot(PMGBinaryTreeNode* root)
{
	if (nullptr == root)
	{
		return false;
	}
	_root = root;

	return true;
}

void PMGBinaryTree::PreOrderTraversal(PMGBinaryTreeNode* Node)
{
	if (nullptr == Node)
	{
		return;
	}
	PreOrderTraversal(Node->GetLeftNode());
	PreOrderTraversal(Node->GetRightNode());
}
