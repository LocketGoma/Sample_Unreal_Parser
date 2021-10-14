// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class JsonDocument;

class JSONPARSER_API JsonCore
{
//�⺻ ������ �� �Ҹ����Դϴ�.
private:
	explicit JsonCore();
			~JsonCore();

//�⺻ ȣ�����Դϴ�.
public:
	static JsonCore* open();
	bool initialize();
	bool destroy();


public:
	JsonDocument& openfile(const char* filePath);


};
