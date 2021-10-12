// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGMapManager.h"
#include "PMGMapGenerator.h"


// Sets default values
APMGMapManager::APMGMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_generator = new PMGMapGenerator();

}

// Called when the game starts or when spawned
void APMGMapManager::BeginPlay()
{
	Super::BeginPlay();
	SetInputParametors(_count, _width, _height, _size);
	
	FActorSpawnParameters spawnParametors; 
	spawnParametors.Owner = this;

	//GetWorld()->SpawnActor<AActor>(_OriginalRoomActor, FVector(50, 10, 1), FRotator(), spawnParametors);

	MakeRoomFromGenerator();
}

// Called every frame
void APMGMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APMGMapManager::SetInputParametors(uint32 count, uint32 width, uint32 height, uint32 interval)
{
	_generator->SetInputParametors(count, width, height, interval);
	_generator->GenerateRoom(10);
	return true;
}
//100 = 1m = 100% (scale x 1)
void APMGMapManager::MakeRoomFromGenerator()
{
	RoomArray roomArray;
	_generator->GetRoomArray(roomArray);

	FActorSpawnParameters spawnParametors;
	for (int32 ii = 0; ii < roomArray.Num(); ++ii)
	{
		RoomData roomData = roomArray[ii];

		if (0 > roomArray[ii]._maxVector.X - roomArray[ii]._minVector.X)
		{
			;
		}
		if (0 > roomArray[ii]._maxVector.Y - roomArray[ii]._minVector.Y)
		{
			;
		}


		GetWorld()->SpawnActor<AActor>(_OriginalRoomActor, FVector(roomArray[ii]._minVector.X, roomArray[ii]._minVector.Y, 0.01)*100, FRotator(0,0,0), spawnParametors)->SetActorScale3D(FVector((roomArray[ii]._maxVector.X - roomArray[ii]._minVector.X)/10, (roomArray[ii]._maxVector.Y - roomArray[ii]._minVector.Y)/10, 1));
	}

}

void APMGMapManager::MakeRoomFromJson()
{
}

void APMGMapManager::ResetRoom()
{
}
