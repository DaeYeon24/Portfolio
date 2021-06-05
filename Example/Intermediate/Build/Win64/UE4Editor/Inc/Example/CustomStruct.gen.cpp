// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Example/CustomStruct.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomStruct() {}
// Cross Module References
	EXAMPLE_API UScriptStruct* Z_Construct_UScriptStruct_FCustomStruct();
	UPackage* Z_Construct_UPackage__Script_Example();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
class UScriptStruct* FCustomStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern EXAMPLE_API uint32 Get_Z_Construct_UScriptStruct_FCustomStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCustomStruct, Z_Construct_UPackage__Script_Example(), TEXT("CustomStruct"), sizeof(FCustomStruct), Get_Z_Construct_UScriptStruct_FCustomStruct_Hash());
	}
	return Singleton;
}
template<> EXAMPLE_API UScriptStruct* StaticStruct<FCustomStruct>()
{
	return FCustomStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCustomStruct(FCustomStruct::StaticStruct, TEXT("/Script/Example"), TEXT("CustomStruct"), false, nullptr, nullptr);
static struct FScriptStruct_Example_StaticRegisterNativesFCustomStruct
{
	FScriptStruct_Example_StaticRegisterNativesFCustomStruct()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CustomStruct")),new UScriptStruct::TCppStructOps<FCustomStruct>);
	}
} ScriptStruct_Example_StaticRegisterNativesFCustomStruct;
	struct Z_Construct_UScriptStruct_FCustomStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_actor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_actor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_i_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_i;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_f_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_f;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "CustomStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCustomStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCustomStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_actor_MetaData[] = {
		{ "Category", "CustomStruct" },
		{ "ModuleRelativePath", "CustomStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomStruct, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_actor_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_actor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_i_MetaData[] = {
		{ "Category", "CustomStruct" },
		{ "ModuleRelativePath", "CustomStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_i = { "i", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomStruct, i), METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_i_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_i_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_f_MetaData[] = {
		{ "Category", "CustomStruct" },
		{ "ModuleRelativePath", "CustomStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_f = { "f", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomStruct, f), METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_f_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_f_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCustomStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_actor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_i,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomStruct_Statics::NewProp_f,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCustomStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Example,
		nullptr,
		&NewStructOps,
		"CustomStruct",
		sizeof(FCustomStruct),
		alignof(FCustomStruct),
		Z_Construct_UScriptStruct_FCustomStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000011),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCustomStruct()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCustomStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Example();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CustomStruct"), sizeof(FCustomStruct), Get_Z_Construct_UScriptStruct_FCustomStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCustomStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCustomStruct_Hash() { return 3480090496U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
