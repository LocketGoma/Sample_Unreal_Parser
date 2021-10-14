// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

typedef struct RoomData
{
public:
	RoomData()
	{
		_vMinVector = FVector::ZeroVector;
		_vMaxVector = FVector::ZeroVector;
	}
	RoomData(FVector& vMinVector, FVector& vMaxVector)
	{
		_vMinVector = vMinVector;
		_vMaxVector = vMaxVector;
	}

public:
	FVector _vMinVector;
	FVector _vMaxVector;

}FRoomData;

typedef TArray<FRoomData> FArrayOfRoomData;