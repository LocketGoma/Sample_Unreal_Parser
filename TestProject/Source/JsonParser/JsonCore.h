// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

class JsonDocument;

class JSONPARSER_API JsonCore
{
//기본 생성자 및 소멸자입니다.
private:
	explicit JsonCore();
			~JsonCore();

//기본 호출자입니다.
public:
	static JsonCore* open();
	bool initialize();
	bool destroy();


public:
	JsonDocument& openfile(const char* filePath);


};
