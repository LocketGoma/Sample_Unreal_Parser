// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGBinaryTreeNode.h"

PMGBinaryTreeNode::PMGBinaryTreeNode() : _ready(false)
{
    initialize();
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

bool PMGBinaryTreeNode::initialize()
{
    _leftNode = nullptr;
    _rightNode = nullptr;

    _ready = true;

    return true;
}

bool PMGBinaryTreeNode::destroy()
{
    if (nullptr != _leftNode)
    {
        _leftNode->destroy();
    }
    if (nullptr != _rightNode)
    {
        _rightNode->destroy();
    }

    delete _leftNode;
    delete _rightNode;

    _ready = false;


    return true;
}

bool PMGBinaryTreeNode::setLeftNode(PMGBinaryTreeNode* node)
{
    _leftNode = node;

    return true;
}

bool PMGBinaryTreeNode::setRightNode(PMGBinaryTreeNode* node)
{
    _rightNode = node;

    return true;
}

bool PMGBinaryTreeNode::setNode(PMGBinaryTreeNode* left, PMGBinaryTreeNode* right)
{
    _leftNode   = left;
    _rightNode  = right;

    return true;
}

bool PMGBinaryTreeNode::setRoomData(RoomData& data)
{
    if ((false == _roomData._minVector.IsNearlyZero()) && (false == _roomData._maxVector.IsNearlyZero()))
    {
        //�̹� ���� �� ����̹Ƿ� �߰� ���� ���ֵ��� ����.
        return false;
    }

    _roomData = data;

    return true;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::getLeftNode()
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::getRightNode()
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

RoomData& PMGBinaryTreeNode::getRoomData()
{
    if (false == _ready)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");        
    }

    return _roomData;
    
}
