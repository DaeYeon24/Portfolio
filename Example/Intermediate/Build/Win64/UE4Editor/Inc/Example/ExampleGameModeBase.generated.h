// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EXAMPLE_ExampleGameModeBase_generated_h
#error "ExampleGameModeBase.generated.h already included, missing '#pragma once' in ExampleGameModeBase.h"
#endif
#define EXAMPLE_ExampleGameModeBase_generated_h

#define Example_Source_Example_ExampleGameModeBase_h_15_SPARSE_DATA
#define Example_Source_Example_ExampleGameModeBase_h_15_RPC_WRAPPERS
#define Example_Source_Example_ExampleGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Example_Source_Example_ExampleGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAExampleGameModeBase(); \
	friend struct Z_Construct_UClass_AExampleGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AExampleGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Example"), NO_API) \
	DECLARE_SERIALIZER(AExampleGameModeBase)


#define Example_Source_Example_ExampleGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAExampleGameModeBase(); \
	friend struct Z_Construct_UClass_AExampleGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AExampleGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Example"), NO_API) \
	DECLARE_SERIALIZER(AExampleGameModeBase)


#define Example_Source_Example_ExampleGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AExampleGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AExampleGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AExampleGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AExampleGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AExampleGameModeBase(AExampleGameModeBase&&); \
	NO_API AExampleGameModeBase(const AExampleGameModeBase&); \
public:


#define Example_Source_Example_ExampleGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AExampleGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AExampleGameModeBase(AExampleGameModeBase&&); \
	NO_API AExampleGameModeBase(const AExampleGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AExampleGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AExampleGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AExampleGameModeBase)


#define Example_Source_Example_ExampleGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define Example_Source_Example_ExampleGameModeBase_h_12_PROLOG
#define Example_Source_Example_ExampleGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Example_Source_Example_ExampleGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Example_Source_Example_ExampleGameModeBase_h_15_SPARSE_DATA \
	Example_Source_Example_ExampleGameModeBase_h_15_RPC_WRAPPERS \
	Example_Source_Example_ExampleGameModeBase_h_15_INCLASS \
	Example_Source_Example_ExampleGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Example_Source_Example_ExampleGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Example_Source_Example_ExampleGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Example_Source_Example_ExampleGameModeBase_h_15_SPARSE_DATA \
	Example_Source_Example_ExampleGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Example_Source_Example_ExampleGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	Example_Source_Example_ExampleGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXAMPLE_API UClass* StaticClass<class AExampleGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Example_Source_Example_ExampleGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
