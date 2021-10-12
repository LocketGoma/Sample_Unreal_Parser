// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGMapManager.h"
#include "PMGMapGenerator.h"


// Sets default values
APMGMapManager::APMGMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APMGMapManager::BeginPlay()
{
	Super::BeginPlay();
	
	PMGMapGenerator* generator = new PMGMapGenerator();	
	generator->SetInputParametors(128, 100, 100, 1, 128);
	generator->GenerateRoom(10);

}

// Called every frame
void APMGMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

