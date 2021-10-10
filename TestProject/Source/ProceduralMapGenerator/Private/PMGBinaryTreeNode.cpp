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
        //에러 발생. (메모리 누수 위험)
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
        //이미 값이 들어간 노드이므로 추가 값을 못넣도록 제한.
        return false;
    }

    _roomData = data;

    return true;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::getLeftNode()
{
    if (false == _ready)
    {
        //경고 발생
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::getRightNode()
{
    if (false == _ready)
    {
        //경고 발생
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

RoomData& PMGBinaryTreeNode::getRoomData()
{
    if (false == _ready)
    {
        //경고 발생
        _ASSERT("Data Not Set!");        
    }

    return _roomData;
    
}
