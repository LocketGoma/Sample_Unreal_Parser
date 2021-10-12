// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProceduralMapGenerator/Public/PMGMapManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePMGMapManager() {}
// Cross Module References
	PROCEDURALMAPGENERATOR_API UClass* Z_Construct_UClass_APMGMapManager_NoRegister();
	PROCEDURALMAPGENERATOR_API UClass* Z_Construct_UClass_APMGMapManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ProceduralMapGenerator();
// End Cross Module References
	void APMGMapManager::StaticRegisterNativesAPMGMapManager()
	{
	}
	UClass* Z_Construct_UClass_APMGMapManager_NoRegister()
	{
		return APMGMapManager::StaticClass();
	}
	struct Z_Construct_UClass_APMGMapManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APMGMapManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProceduralMapGenerator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PMGMapManager.h" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APMGMapManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APMGMapManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APMGMapManager_Statics::ClassParams = {
		&APMGMapManager::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APMGMapManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APMGMapManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APMGMapManager, 36229145);
	template<> PROCEDURALMAPGENERATOR_API UClass* StaticClass<APMGMapManager>()
	{
		return APMGMapManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APMGMapManager(Z_Construct_UClass_APMGMapManager, &APMGMapManager::StaticClass, TEXT("/Script/ProceduralMapGenerator"), TEXT("APMGMapManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APMGMapManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
