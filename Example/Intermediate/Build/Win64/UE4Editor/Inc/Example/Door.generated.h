// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EXAMPLE_Door_generated_h
#error "Door.generated.h already included, missing '#pragma once' in Door.h"
#endif
#define EXAMPLE_Door_generated_h

#define Example_Source_Example_Door_h_13_SPARSE_DATA
#define Example_Source_Example_Door_h_13_RPC_WRAPPERS
#define Example_Source_Example_Door_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define Example_Source_Example_Door_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADoor(); \
	friend struct Z_Construct_UClass_ADoor_Statics; \
public: \
	DECLARE_CLASS(ADoor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Example"), NO_API) \
	DECLARE_SERIALIZER(ADoor)


#define Example_Source_Example_Door_h_13_INCLASS \
private: \
	static void StaticRegisterNativesADoor(); \
	friend struct Z_Construct_UClass_ADoor_Statics; \
public: \
	DECLARE_CLASS(ADoor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Example"), NO_API) \
	DECLARE_SERIALIZER(ADoor)


#define Example_Source_Example_Door_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoor(ADoor&&); \
	NO_API ADoor(const ADoor&); \
public:


#define Example_Source_Example_Door_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADoor(ADoor&&); \
	NO_API ADoor(const ADoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADoor)


#define Example_Source_Example_Door_h_13_PRIVATE_PROPERTY_OFFSET
#define Example_Source_Example_Door_h_10_PROLOG
#define Example_Source_Example_Door_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Example_Source_Example_Door_h_13_PRIVATE_PROPERTY_OFFSET \
	Example_Source_Example_Door_h_13_SPARSE_DATA \
	Example_Source_Example_Door_h_13_RPC_WRAPPERS \
	Example_Source_Example_Door_h_13_INCLASS \
	Example_Source_Example_Door_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Example_Source_Example_Door_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Example_Source_Example_Door_h_13_PRIVATE_PROPERTY_OFFSET \
	Example_Source_Example_Door_h_13_SPARSE_DATA \
	Example_Source_Example_Door_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Example_Source_Example_Door_h_13_INCLASS_NO_PURE_DECLS \
	Example_Source_Example_Door_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXAMPLE_API UClass* StaticClass<class ADoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Example_Source_Example_Door_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
