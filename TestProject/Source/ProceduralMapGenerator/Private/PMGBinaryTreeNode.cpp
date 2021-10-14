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
        //���� �߻�. (�޸� ���� ����)
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
        //�̹� ���� �� ����̹Ƿ� �߰� ���� ���ֵ��� ����.
        return false;
    }

    _roomDataNode = roomDataNode;

    return true;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetLeftNode(void)
{
    if (false == _bReady)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _leftNode;
}

PMGBinaryTreeNode* PMGBinaryTreeNode::GetRightNode(void)
{
    if (false == _bReady)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");
        return nullptr;
    }
    return _rightNode;
}

FRoomData& PMGBinaryTreeNode::GetRoomData(void)
{
    if (false == _bReady)
    {
        //��� �߻�
        _ASSERT("Data Not Set!");        
    }

    return _roomDataNode;
    
}
