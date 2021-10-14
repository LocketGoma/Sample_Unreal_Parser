// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGBinaryTreeNode.h"

PMGBinaryTreeNode::PMGBinaryTreeNode(void) : _bReady(false)
{
    Initialize();
}

PMGBinaryTreeNode::PMGBinaryTreeNode(RoomData roomDataNode)
{
    _roomDataNode = roomDataNode;
    Initialize();
}

PMGBinaryTreeNode::~PMGBinaryTreeNode(void)
{
    if (true == _bReady)
    {
        //에러 발생. (메모리 누수 위험)
        _ASSERT("Memory leak!");
    }

    _leftNode = nullptr;
    _rightNode = nullptr;
}

void PMGBinaryTreeNode::Initialize(void)
{
    _leftNode = nullptr;
    _rightNode = nullptr;

    _bReady = true;    
}

void PMGBinaryTreeNode::Destroy(void)
{
    if (nullptr != _leftNode)
    {
        _leftNode->Destroy();
    }
    if (nullptr != _rightNode)
    {
        _rightNode->Destroy();
    }

    delete _leftNode;
    delete _rightNode;

    _bReady = false;

}

bool PMGBinaryTreeNode::SetLeftNode(PMGBinaryTreeNode* leftNode)
{
    _leftNode = leftNode;

    return true;
}

bool PMGBinaryTreeNode::SetRightNode(PMGBinaryTreeNode* rightNode)
{
    _rightNode = rightNode;

    return true;
}

bool PMGBinaryTreeNode::SetNode(PMGBinaryTreeNode* left, PMGBinaryTreeNode* right)
{
    _leftNode   = left;
    _rightNode  = right;

    return true;
}

bool PMGBinaryTreeNode::SetRoomData(RoomData& roomDataNode)
{
    if ((false == _roomDataNode._vMinVector.IsNearlyZero()) && (false == _roomDataNode._vMaxVector.IsNearlyZero()))
    {
        //이미 값이 들어간 노드이므로 추가 값을 못넣도록 제한.
        return false;
    }

    _roomDataNode = roomDataNode;

    return true;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetLeftNode(void)
{
    if (false == _bReady)
    {
        //경고 발생
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetRightNode(void)
{
    if (false == _bReady)
    {
        //경고 발생
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

FRoomData& PMGBinaryTreeNode::GetRoomData(void)
{
    if (false == _bReady)
    {
        //경고 발생
        _ASSERT("Data Not Set!");        
    }

    return _roomDataNode;
    
}
