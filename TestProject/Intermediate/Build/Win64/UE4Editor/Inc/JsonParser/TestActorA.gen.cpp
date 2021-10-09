// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "JsonParser/TestActorA.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestActorA() {}
// Cross Module References
	JSONPARSER_API UClass* Z_Construct_UClass_ATestActorA_NoRegister();
	JSONPARSER_API UClass* Z_Construct_UClass_ATestActorA();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_JsonParser();
// End Cross Module References
	void ATestActorA::StaticRegisterNativesATestActorA()
	{
	}
	UClass* Z_Construct_UClass_ATestActorA_NoRegister()
	{
		return ATestActorA::StaticClass();
	}
	struct Z_Construct_UClass_ATestActorA_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestActorA_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_JsonParser,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestActorA_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TestActorA.h" },
		{ "ModuleRelativePath", "TestActorA.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestActorA_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestActorA>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATestActorA_Statics::ClassParams = {
		&ATestActorA::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATestActorA_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATestActorA_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATestActorA()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATestActorA_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATestActorA, 1798657430);
	template<> JSONPARSER_API UClass* StaticClass<ATestActorA>()
	{
		return ATestActorA::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATestActorA(Z_Construct_UClass_ATestActorA, &ATestActorA::StaticClass, TEXT("/Script/JsonParser"), TEXT("ATestActorA"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestActorA);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
