// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../ProceduralMapGenerator.h"
#include "RoomComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROCEDURALMAPGENERATOR_API URoomComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URoomComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay(void) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void SetRoomData(FRoomData& roomdata);
	void SetTransformFromRoomData(void);

private:
	FRoomData _roomData;
		
};
