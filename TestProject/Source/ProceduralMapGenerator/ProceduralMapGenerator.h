// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

typedef struct RoomData
{
public:
	RoomData()
	{
		_minVector = FVector::ZeroVector;
		_maxVector = FVector::ZeroVector;
	}
	RoomData(FVector& minVector, FVector& maxVector)
	{
		_minVector = minVector;
		_maxVector = maxVector;
	}

public:
	FVector _minVector;
	FVector _maxVector;

}RoomData;