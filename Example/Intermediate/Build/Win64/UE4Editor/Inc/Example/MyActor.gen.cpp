// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Example/MyActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActor() {}
// Cross Module References
	EXAMPLE_API UClass* Z_Construct_UClass_AMyActor_NoRegister();
	EXAMPLE_API UClass* Z_Construct_UClass_AMyActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Example();
// End Cross Module References
	DEFINE_FUNCTION(AMyActor::execCalculateDPS)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CalculateDPS();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyActor::execCallFromCpp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CallFromCpp_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AMyActor_CallFromCpp = FName(TEXT("CallFromCpp"));
	void AMyActor::CallFromCpp()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMyActor_CallFromCpp),NULL);
	}
	void AMyActor::StaticRegisterNativesAMyActor()
	{
		UClass* Class = AMyActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateDPS", &AMyActor::execCalculateDPS },
			{ "CallFromCpp", &AMyActor::execCallFromCpp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyActor_CalculateDPS_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyActor_CalculateDPS_Statics::Function_MetaDataParams[] = {
		{ "Category", "Damage" },
		{ "Comment", "// \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90 \xed\x99\x9c\xec\x9a\xa9\xed\x95\x98\xeb\xa0\xa4\xeb\xa9\xb4 UFUNCTION \xec\x82\xac\xec\x9a\xa9\n" },
		{ "ModuleRelativePath", "MyActor.h" },
		{ "ToolTip", "\xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90 \xed\x99\x9c\xec\x9a\xa9\xed\x95\x98\xeb\xa0\xa4\xeb\xa9\xb4 UFUNCTION \xec\x82\xac\xec\x9a\xa9" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyActor_CalculateDPS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyActor, nullptr, "CalculateDPS", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyActor_CalculateDPS_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActor_CalculateDPS_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyActor_CalculateDPS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyActor_CalculateDPS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyActor_CallFromCpp_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyActor_CallFromCpp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Damage" },
		{ "Comment", "// \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c CPP\xeb\xa1\x9c \xeb\xb0\x9b\xec\x95\x84\xec\x98\xa4\xea\xb8\xb0\n" },
		{ "ModuleRelativePath", "MyActor.h" },
		{ "ToolTip", "\xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c CPP\xeb\xa1\x9c \xeb\xb0\x9b\xec\x95\x84\xec\x98\xa4\xea\xb8\xb0" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyActor_CallFromCpp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyActor, nullptr, "CallFromCpp", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyActor_CallFromCpp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActor_CallFromCpp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyActor_CallFromCpp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyActor_CallFromCpp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyActor_NoRegister()
	{
		return AMyActor::StaticClass();
	}
	struct Z_Construct_UClass_AMyActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_totalDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_totalDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_damageTimeInSeconds_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damageTimeInSeconds;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_damagePerSecond_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_damagePerSecond;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CharacterName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_attackable_MetaData[];
#endif
		static void NewProp_attackable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_attackable;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_str_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_str;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Example,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyActor_CalculateDPS, "CalculateDPS" }, // 1288582731
		{ &Z_Construct_UFunction_AMyActor_CallFromCpp, "CallFromCpp" }, // 1897457974
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyActor.h" },
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_totalDamage_MetaData[] = {
		{ "Category", "Damage" },
		{ "Comment", "// \xec\x9c\xa0\xed\x94\x84\xeb\xa1\x9c\xed\x8d\xbc\xed\x8b\xb0\xeb\xa1\x9c \xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90 \xeb\x85\xb8\xec\xb6\x9c, \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xed\x99\x9c\xec\x9a\xa9 \xea\xb0\x80\xeb\x8a\xa5\n// EditAnywhere  = \xec\x97\x90\xeb\x94\x94\xed\x84\xb0 \xeb\x85\xb8\xec\xb6\x9c\n// BlueprintReadWrite = \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xed\x99\x9c\xec\x9a\xa9 (\xeb\xa6\xac\xeb\x93\x9c, \xeb\x9d\xbc\xec\x9d\xb4\xed\x8a\xb8\xeb\xa1\x9c \xec\x9d\xbd\xea\xb8\xb0,\xec\x93\xb0\xea\xb8\xb0 \xea\xb6\x8c\xed\x95\x9c \xeb\xb6\x80\xec\x97\xac)\n// VisibleAnywhere = \xeb\xaa\xa8\xeb\x8b\x88\xed\x84\xb0\xeb\xa7\x81\xeb\xa7\x8c \xea\xb0\x80\xeb\x8a\xa5 \xea\xb0\x92 \xeb\xb3\x80\xea\xb2\xbd \xeb\xb6\x88\xea\xb0\x80\n// Category = \xec\xb9\xb4\xed\x85\x8c\xea\xb3\xa0\xeb\xa6\xac \xec\xa7\x80\xec\xa0\x95\n" },
		{ "ModuleRelativePath", "MyActor.h" },
		{ "ToolTip", "\xec\x9c\xa0\xed\x94\x84\xeb\xa1\x9c\xed\x8d\xbc\xed\x8b\xb0\xeb\xa1\x9c \xec\x97\x90\xeb\x94\x94\xed\x84\xb0\xec\x97\x90 \xeb\x85\xb8\xec\xb6\x9c, \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8 \xed\x99\x9c\xec\x9a\xa9 \xea\xb0\x80\xeb\x8a\xa5\nEditAnywhere  = \xec\x97\x90\xeb\x94\x94\xed\x84\xb0 \xeb\x85\xb8\xec\xb6\x9c\nBlueprintReadWrite = \xeb\xb8\x94\xeb\xa3\xa8\xed\x94\x84\xeb\xa6\xb0\xed\x8a\xb8\xec\x97\x90\xec\x84\x9c \xed\x99\x9c\xec\x9a\xa9 (\xeb\xa6\xac\xeb\x93\x9c, \xeb\x9d\xbc\xec\x9d\xb4\xed\x8a\xb8\xeb\xa1\x9c \xec\x9d\xbd\xea\xb8\xb0,\xec\x93\xb0\xea\xb8\xb0 \xea\xb6\x8c\xed\x95\x9c \xeb\xb6\x80\xec\x97\xac)\nVisibleAnywhere = \xeb\xaa\xa8\xeb\x8b\x88\xed\x84\xb0\xeb\xa7\x81\xeb\xa7\x8c \xea\xb0\x80\xeb\x8a\xa5 \xea\xb0\x92 \xeb\xb3\x80\xea\xb2\xbd \xeb\xb6\x88\xea\xb0\x80\nCategory = \xec\xb9\xb4\xed\x85\x8c\xea\xb3\xa0\xeb\xa6\xac \xec\xa7\x80\xec\xa0\x95" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_totalDamage = { "totalDamage", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyActor, totalDamage), METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_totalDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_totalDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_damageTimeInSeconds_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_damageTimeInSeconds = { "damageTimeInSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyActor, damageTimeInSeconds), METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_damageTimeInSeconds_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_damageTimeInSeconds_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_damagePerSecond_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_damagePerSecond = { "damagePerSecond", nullptr, (EPropertyFlags)0x0010000000022015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyActor, damagePerSecond), METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_damagePerSecond_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_damagePerSecond_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_CharacterName_MetaData[] = {
		{ "Category", "MyActor" },
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_CharacterName = { "CharacterName", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyActor, CharacterName), METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_CharacterName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_CharacterName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_attackable_MetaData[] = {
		{ "Category", "MyActor" },
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif
	void Z_Construct_UClass_AMyActor_Statics::NewProp_attackable_SetBit(void* Obj)
	{
		((AMyActor*)Obj)->attackable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_attackable = { "attackable", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyActor), &Z_Construct_UClass_AMyActor_Statics::NewProp_attackable_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_attackable_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_attackable_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyActor_Statics::NewProp_str_MetaData[] = {
		{ "Category", "Damage" },
		{ "Comment", "// test\n" },
		{ "ModuleRelativePath", "MyActor.h" },
		{ "ToolTip", "test" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMyActor_Statics::NewProp_str = { "str", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyActor, str), METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::NewProp_str_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::NewProp_str_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_totalDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_damageTimeInSeconds,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_damagePerSecond,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_CharacterName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_attackable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyActor_Statics::NewProp_str,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyActor_Statics::ClassParams = {
		&AMyActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyActor, 4024851499);
	template<> EXAMPLE_API UClass* StaticClass<AMyActor>()
	{
		return AMyActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyActor(Z_Construct_UClass_AMyActor, &AMyActor::StaticClass, TEXT("/Script/Example"), TEXT("AMyActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
