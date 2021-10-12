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
        //���� �߻�. (�޸� ���� ����)
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
        //�̹� ���� �� ����̹Ƿ� �߰� ���� ���ֵ��� ����.
        return false;
    }

    _roomData = data;

    return true;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetLeftNode()
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetRightNode()
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

RoomData& PMGBinaryTreeNode::GetRoomData()
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");        
    }

    return _roomData;
    
}
