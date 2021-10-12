// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGBinaryTreeNode.h"

PMGBinaryTreeNode::PMGBinaryTreeNode() : _ready(false)
{
    Initialize();
}

PMGBinaryTreeNode::PMGBinaryTreeNode(RoomData roomData)
{
    _roomData = roomData;
    Initialize();
}

PMGBinaryTreeNode::~PMGBinaryTreeNode()
{
    if (true == _ready)
    {
        //에러 발생. (메모리 누수 위험)
        _ASSERT("Memory leak!");
    }

    _leftNode = nullptr;
    _rightNode = nullptr;
}

bool PMGBinaryTreeNode::Initialize()
{
    _leftNode = nullptr;
    _rightNode = nullptr;

    _ready = true;

    return true;
}

bool PMGBinaryTreeNode::Destroy()
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

    _ready = false;


    return true;
}

bool PMGBinaryTreeNode::SetLeftNode(PMGBinaryTreeNode* node)
{
    _leftNode = node;

    return true;
}

bool PMGBinaryTreeNode::SetRightNode(PMGBinaryTreeNode* node)
{
    _rightNode = node;

    return true;
}

bool PMGBinaryTreeNode::SetNode(PMGBinaryTreeNode* left, PMGBinaryTreeNode* right)
{
    _leftNode   = left;
    _rightNode  = right;

    return true;
}

bool PMGBinaryTreeNode::SetRoomData(RoomData& data)
{
    if ((false == _roomData._minVector.IsNearlyZero()) && (false == _roomData._maxVector.IsNearlyZero()))
    {
        //이미 값이 들어간 노드이므로 추가 값을 못넣도록 제한.
        return false;
    }

    _roomData = data;

    return true;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetLeftNode()
{
    if (false == _ready)
    {
        //경고 발생
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetRightNode()
{
    if (false == _ready)
    {
        //경고 발생
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

RoomData& PMGBinaryTreeNode::GetRoomData()
{
    if (false == _ready)
    {
        //경고 발생
        _ASSERT("Data Not Set!");        
    }

    return _roomData;
    
}
