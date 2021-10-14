// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGMapManager.h"
#include "PMGMapGenerator.h"


// Sets default values
APMGMapManager::APMGMapManager() : _PMGGenerator(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	

	Initialize();
}

bool APMGMapManager::Initialize(void)
{
	_PMGGenerator = new PMGMapGenerator();

	return true;
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

void APMGMapManager::GetRoomArray(FArrayOfRoomData& roomarray)
{
	_PMGGenerator->GetRoomArray(roomarray);
}

bool APMGMapManager::SetInputParametors(uint32 count, uint32 width, uint32 height, uint32 interval)
{
	_PMGGenerator->SetInputParametors(count, width, height, interval);
	_PMGGenerator->GenerateRoom(10);
	return true;
}
//100 = 1m = 100% (scale x 1)
void APMGMapManager::MakeRoomFromGenerator()
{
	FArrayOfRoomData roomArray;
	_PMGGenerator->GetRoomArray(roomArray);

	FActorSpawnParameters spawnParametors;
	for (int32 ii = 0; ii < roomArray.Num(); ++ii)
	{
		FVector actorSpawnPosition = FVector(roomArray[ii]._vMinVector.X + ((roomArray[ii]._vMaxVector.X - roomArray[ii]._vMinVector.X) / 2), roomArray[ii]._vMinVector.Y + ((roomArray[ii]._vMaxVector.Y - roomArray[ii]._vMinVector.Y) / 2), 0.01) * 100;
		FVector actorSpawnScale = FVector((roomArray[ii]._vMaxVector.X - roomArray[ii]._vMinVector.X), (roomArray[ii]._vMaxVector.Y - roomArray[ii]._vMinVector.Y), 1);

		GetWorld()->SpawnActor<AActor>(_OriginalRoomActor, actorSpawnPosition, FRotator(0,0,0), spawnParametors)->SetActorScale3D(actorSpawnScale);
	}

}

void APMGMapManager::MakeRoomFromJson()
{
	;
}

void APMGMapManager::ResetRoom()
{
	;
}
