// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGBinaryTreeNode.h"

PMGBinaryTreeNode::PMGBinaryTreeNode(void) : _ready(false)
{
    Initialize(void);
}

PMGBinaryTreeNode::PMGBinaryTreeNode(RoomData roomData)
{
    _roomData = roomData;
    Initialize(void);
}

PMGBinaryTreeNode::~PMGBinaryTreeNode(void)
{
    if (true == _ready)
    {
        //���� �߻�. (�޸� ���� ����)
        _ASSERT("Memory leak!");
    }

    _leftNode = nullptr;
    _rightNode = nullptr;
}

bool PMGBinaryTreeNode::Initialize(void)
{
    _leftNode = nullptr;
    _rightNode = nullptr;

    _ready = true;

    return true;
}

bool PMGBinaryTreeNode::Destroy(void)
{
    if (nullptr != _leftNode)
    {
        _leftNode->Destroy(void);
    }
    if (nullptr != _rightNode)
    {
        _rightNode->Destroy(void);
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

PMGBinaryTreeNode* PMGBinaryTreeNode::GetLeftNode(void)
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetRightNode(void)
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

RoomData& PMGBinaryTreeNode::GetRoomData(void)
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");        
    }

    return _roomData;
    
}
