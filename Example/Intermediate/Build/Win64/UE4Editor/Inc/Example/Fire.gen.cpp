// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Example/Fire.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFire() {}
// Cross Module References
	EXAMPLE_API UClass* Z_Construct_UClass_AFire_NoRegister();
	EXAMPLE_API UClass* Z_Construct_UClass_AFire();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Example();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFire::execOffFire)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OffFire();
		P_NATIVE_END;
	}
	void AFire::StaticRegisterNativesAFire()
	{
		UClass* Class = AFire::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OffFire", &AFire::execOffFire },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFire_OffFire_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFire_OffFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Fire.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFire_OffFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFire, nullptr, "OffFire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFire_OffFire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFire_OffFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFire_OffFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFire_OffFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFire_NoRegister()
	{
		return AFire::StaticClass();
	}
	struct Z_Construct_UClass_AFire_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_fireParticle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_fireParticle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_fireTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FInt8PropertyParams NewProp_fireTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFire_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Example,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFire_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFire_OffFire, "OffFire" }, // 1424931772
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFire_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// ??\xc3\xb3???\xe2\xb8\xa6 ?????\xd2\xb6??? ?\xd7\xbb? ?\xd8\xb4? \xc5\xac???? ???\xca\xb7???\xc6\xae ???????? ???? ?\xdb\xbc??? ??\n" },
		{ "IncludePath", "Fire.h" },
		{ "ModuleRelativePath", "Fire.h" },
		{ "ToolTip", "??\xc3\xb3???\xe2\xb8\xa6 ?????\xd2\xb6??? ?\xd7\xbb? ?\xd8\xb4? \xc5\xac???? ???\xca\xb7???\xc6\xae ???????? ???? ?\xdb\xbc??? ??" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFire_Statics::NewProp_fireParticle_MetaData[] = {
		{ "Category", "Fire" },
		{ "Comment", "//<Engine/Classes/Particles/ParticleSystemComponent.h> ????\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Fire.h" },
		{ "ToolTip", "<Engine/Classes/Particles/ParticleSystemComponent.h> ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFire_Statics::NewProp_fireParticle = { "fireParticle", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFire, fireParticle), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFire_Statics::NewProp_fireParticle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFire_Statics::NewProp_fireParticle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFire_Statics::NewProp_fireTime_MetaData[] = {
		{ "Category", "Fire" },
		{ "ModuleRelativePath", "Fire.h" },
	};
#endif
	const UE4CodeGen_Private::FInt8PropertyParams Z_Construct_UClass_AFire_Statics::NewProp_fireTime = { "fireTime", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Int8, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFire, fireTime), METADATA_PARAMS(Z_Construct_UClass_AFire_Statics::NewProp_fireTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFire_Statics::NewProp_fireTime_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFire_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFire_Statics::NewProp_fireParticle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFire_Statics::NewProp_fireTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFire_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFire>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFire_Statics::ClassParams = {
		&AFire::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFire_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFire_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFire_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFire_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFire()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFire_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFire, 4127253834);
	template<> EXAMPLE_API UClass* StaticClass<AFire>()
	{
		return AFire::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFire(Z_Construct_UClass_AFire, &AFire::StaticClass, TEXT("/Script/Example"), TEXT("AFire"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFire);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
