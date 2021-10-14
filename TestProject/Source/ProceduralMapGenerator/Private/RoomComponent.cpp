// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomComponent.h"

// Sets default values for this component's properties
URoomComponent::URoomComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URoomComponent::BeginPlay()
{
	Super::BeginPlay();


}


// Called every frame
void URoomComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URoomComponent::SetRoomData(FRoomData& roomdata)
{
	_roomData = roomdata;
}

void URoomComponent::SetTransformFromRoomData()
{
	GetOwner()->GetRootComponent()->SetRelativeScale3D(FVector(_roomData._vMaxVector.X - _roomData._vMinVector.X, _roomData._vMaxVector.Y - _roomData._vMinVector.Y, _roomData._vMaxVector.Z - _roomData._vMinVector.Z));
	GetOwner()->GetRootComponent()->SetUsingAbsoluteScale(true);
}

