// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef JSONPARSER_TestActorA_generated_h
#error "TestActorA.generated.h already included, missing '#pragma once' in TestActorA.h"
#endif
#define JSONPARSER_TestActorA_generated_h

#define TestProject_Source_JsonParser_TestActorA_h_12_SPARSE_DATA
#define TestProject_Source_JsonParser_TestActorA_h_12_RPC_WRAPPERS
#define TestProject_Source_JsonParser_TestActorA_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define TestProject_Source_JsonParser_TestActorA_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATestActorA(); \
	friend struct Z_Construct_UClass_ATestActorA_Statics; \
public: \
	DECLARE_CLASS(ATestActorA, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JsonParser"), NO_API) \
	DECLARE_SERIALIZER(ATestActorA)


#define TestProject_Source_JsonParser_TestActorA_h_12_INCLASS \
private: \
	static void StaticRegisterNativesATestActorA(); \
	friend struct Z_Construct_UClass_ATestActorA_Statics; \
public: \
	DECLARE_CLASS(ATestActorA, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/JsonParser"), NO_API) \
	DECLARE_SERIALIZER(ATestActorA)


#define TestProject_Source_JsonParser_TestActorA_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATestActorA(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATestActorA) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestActorA); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestActorA); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestActorA(ATestActorA&&); \
	NO_API ATestActorA(const ATestActorA&); \
public:


#define TestProject_Source_JsonParser_TestActorA_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestActorA(ATestActorA&&); \
	NO_API ATestActorA(const ATestActorA&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestActorA); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestActorA); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATestActorA)


#define TestProject_Source_JsonParser_TestActorA_h_12_PRIVATE_PROPERTY_OFFSET
#define TestProject_Source_JsonParser_TestActorA_h_9_PROLOG
#define TestProject_Source_JsonParser_TestActorA_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestProject_Source_JsonParser_TestActorA_h_12_PRIVATE_PROPERTY_OFFSET \
	TestProject_Source_JsonParser_TestActorA_h_12_SPARSE_DATA \
	TestProject_Source_JsonParser_TestActorA_h_12_RPC_WRAPPERS \
	TestProject_Source_JsonParser_TestActorA_h_12_INCLASS \
	TestProject_Source_JsonParser_TestActorA_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestProject_Source_JsonParser_TestActorA_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestProject_Source_JsonParser_TestActorA_h_12_PRIVATE_PROPERTY_OFFSET \
	TestProject_Source_JsonParser_TestActorA_h_12_SPARSE_DATA \
	TestProject_Source_JsonParser_TestActorA_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	TestProject_Source_JsonParser_TestActorA_h_12_INCLASS_NO_PURE_DECLS \
	TestProject_Source_JsonParser_TestActorA_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> JSONPARSER_API UClass* StaticClass<class ATestActorA>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestProject_Source_JsonParser_TestActorA_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
