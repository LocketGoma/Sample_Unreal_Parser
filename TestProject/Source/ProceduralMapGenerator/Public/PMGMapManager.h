// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "../ProceduralMapGenerator.h"
#include "PMGMapManager.generated.h"

//���漱��
class UStaticMeshComponent;
class PMGMapGenerator;

UENUM()
enum class EGenerateType
{
	GenerateFromGenerator		UMETA(DisplayName = "GenerateFromGenerator"),
	GenerateFromJson			UMETA(DisplayName = "GenerateFromJson")
};

UCLASS()
class PROCEDURALMAPGENERATOR_API APMGMapManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APMGMapManager();

private:
	bool Initialize(void);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	//const RoomArray& GetRoomArray();
	void GetRoomArray(FArrayOfRoomData& roomarray);

//���� ���۰���
public:
	UPROPERTY(EditAnywhere);
	TSubclassOf<class AActor> _OriginalRoomActor;


	UPROPERTY(EditAnywhere, Category = "GenerateParametor | BaseParametor");
	uint32 _height = 0;

	UPROPERTY(EditAnywhere, Category = "GenerateParametor | BaseParametor");
	uint32 _width = 0;

	UPROPERTY(EditAnywhere, Category = "GenerateParametor | BaseParametor");
	uint32 _depth = 0;

	UPROPERTY(EditAnywhere, Category = "GenerateParametor | SizeParametor");
	uint32 _count = 0;

	UPROPERTY(EditAnywhere, Category = "GenerateParametor | SizeParametor");
	uint32 _size = 0;

	UPROPERTY(EditAnywhere, Category = "GenerateParametor | BaseParametor");
	EGenerateType _generateType = EGenerateType::GenerateFromGenerator;
		

	bool SetInputParametors(uint32 count, uint32 height, uint32 width, uint32 size);

//Map Make Part 
public:
	void MakeRoomFromGenerator(void);		//���õ� ���׷����ͷ� ����
	void MakeRoomFromJson(void);			//�о���� Json���Ͽ��� ����


	void ResetRoom(void);					//�ʱ�ȭ

//Generator Machine
private:
	PMGMapGenerator* _PMGGenerator;

};
