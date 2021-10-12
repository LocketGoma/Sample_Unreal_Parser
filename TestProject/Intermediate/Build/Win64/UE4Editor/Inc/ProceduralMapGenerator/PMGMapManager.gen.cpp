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
	PROCEDURALMAPGENERATOR_API UEnum* Z_Construct_UEnum_ProceduralMapGenerator_EGenerateType();
	UPackage* Z_Construct_UPackage__Script_ProceduralMapGenerator();
	PROCEDURALMAPGENERATOR_API UClass* Z_Construct_UClass_APMGMapManager_NoRegister();
	PROCEDURALMAPGENERATOR_API UClass* Z_Construct_UClass_APMGMapManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static UEnum* EGenerateType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProceduralMapGenerator_EGenerateType, Z_Construct_UPackage__Script_ProceduralMapGenerator(), TEXT("EGenerateType"));
		}
		return Singleton;
	}
	template<> PROCEDURALMAPGENERATOR_API UEnum* StaticEnum<EGenerateType>()
	{
		return EGenerateType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EGenerateType(EGenerateType_StaticEnum, TEXT("/Script/ProceduralMapGenerator"), TEXT("EGenerateType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProceduralMapGenerator_EGenerateType_Hash() { return 1381815859U; }
	UEnum* Z_Construct_UEnum_ProceduralMapGenerator_EGenerateType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProceduralMapGenerator();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EGenerateType"), 0, Get_Z_Construct_UEnum_ProceduralMapGenerator_EGenerateType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EGenerateType::GenerateFromGenerator", (int64)EGenerateType::GenerateFromGenerator },
				{ "EGenerateType::GenerateFromJson", (int64)EGenerateType::GenerateFromJson },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "GenerateFromGenerator.DisplayName", "GenerateFromGenerator" },
				{ "GenerateFromGenerator.Name", "EGenerateType::GenerateFromGenerator" },
				{ "GenerateFromJson.DisplayName", "GenerateFromJson" },
				{ "GenerateFromJson.Name", "EGenerateType::GenerateFromJson" },
				{ "ModuleRelativePath", "Public/PMGMapManager.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProceduralMapGenerator,
				nullptr,
				"EGenerateType",
				"EGenerateType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__OriginalRoomActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp__OriginalRoomActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__height_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp__height;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__width_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp__width;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__count_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp__count;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__size_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp__size;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp__generateType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__generateType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp__generateType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::NewProp__OriginalRoomActor_MetaData[] = {
		{ "Category", "PMGMapManager" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__OriginalRoomActor = { "_OriginalRoomActor", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APMGMapManager, _OriginalRoomActor), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::NewProp__OriginalRoomActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::NewProp__OriginalRoomActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::NewProp__height_MetaData[] = {
		{ "Category", "GenerateParametor | BaseParametor" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__height = { "_height", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APMGMapManager, _height), METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::NewProp__height_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::NewProp__height_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::NewProp__width_MetaData[] = {
		{ "Category", "GenerateParametor | BaseParametor" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__width = { "_width", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APMGMapManager, _width), METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::NewProp__width_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::NewProp__width_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::NewProp__count_MetaData[] = {
		{ "Category", "GenerateParametor | SizeParametor" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__count = { "_count", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APMGMapManager, _count), METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::NewProp__count_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::NewProp__count_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::NewProp__size_MetaData[] = {
		{ "Category", "GenerateParametor | SizeParametor" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__size = { "_size", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APMGMapManager, _size), METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::NewProp__size_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::NewProp__size_MetaData)) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType_MetaData[] = {
		{ "Category", "GenerateParametor | BaseParametor" },
		{ "ModuleRelativePath", "Public/PMGMapManager.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType = { "_generateType", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APMGMapManager, _generateType), Z_Construct_UEnum_ProceduralMapGenerator_EGenerateType, METADATA_PARAMS(Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APMGMapManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__OriginalRoomActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__count,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__size,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APMGMapManager_Statics::NewProp__generateType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APMGMapManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APMGMapManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APMGMapManager_Statics::ClassParams = {
		&APMGMapManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APMGMapManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APMGMapManager_Statics::PropPointers),
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
	IMPLEMENT_CLASS(APMGMapManager, 3893215203);
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
