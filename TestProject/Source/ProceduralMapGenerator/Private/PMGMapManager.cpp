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

	GetWorld()->SpawnActor<AActor>(_OriginalRoomActor, FVector(50, 10, 1), FRotator(), spawnParametors);
}

// Called every frame
void APMGMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APMGMapManager::SetInputParametors(uint32 count, uint32 width, uint32 height, uint32 size)
{
	_generator->SetInputParametors(count, width, height, size, 128);
	return true;
}

void APMGMapManager::MakeRoomFromGenerator()
{
}

void APMGMapManager::MakeRoomFromJson()
{
}

void APMGMapManager::ResetRoom()
{
}
