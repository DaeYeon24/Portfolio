// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EXAMPLE_CustomTest_generated_h
#error "CustomTest.generated.h already included, missing '#pragma once' in CustomTest.h"
#endif
#define EXAMPLE_CustomTest_generated_h

#define Example_Source_Example_CustomTest_h_13_SPARSE_DATA
#define Example_Source_Example_CustomTest_h_13_RPC_WRAPPERS
#define Example_Source_Example_CustomTest_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define Example_Source_Example_CustomTest_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACustomTest(); \
	friend struct Z_Construct_UClass_ACustomTest_Statics; \
public: \
	DECLARE_CLASS(ACustomTest, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Example"), NO_API) \
	DECLARE_SERIALIZER(ACustomTest)


#define Example_Source_Example_CustomTest_h_13_INCLASS \
private: \
	static void StaticRegisterNativesACustomTest(); \
	friend struct Z_Construct_UClass_ACustomTest_Statics; \
public: \
	DECLARE_CLASS(ACustomTest, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Example"), NO_API) \
	DECLARE_SERIALIZER(ACustomTest)


#define Example_Source_Example_CustomTest_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACustomTest(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACustomTest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomTest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomTest); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomTest(ACustomTest&&); \
	NO_API ACustomTest(const ACustomTest&); \
public:


#define Example_Source_Example_CustomTest_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACustomTest(ACustomTest&&); \
	NO_API ACustomTest(const ACustomTest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACustomTest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACustomTest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACustomTest)


#define Example_Source_Example_CustomTest_h_13_PRIVATE_PROPERTY_OFFSET
#define Example_Source_Example_CustomTest_h_10_PROLOG
#define Example_Source_Example_CustomTest_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Example_Source_Example_CustomTest_h_13_PRIVATE_PROPERTY_OFFSET \
	Example_Source_Example_CustomTest_h_13_SPARSE_DATA \
	Example_Source_Example_CustomTest_h_13_RPC_WRAPPERS \
	Example_Source_Example_CustomTest_h_13_INCLASS \
	Example_Source_Example_CustomTest_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Example_Source_Example_CustomTest_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Example_Source_Example_CustomTest_h_13_PRIVATE_PROPERTY_OFFSET \
	Example_Source_Example_CustomTest_h_13_SPARSE_DATA \
	Example_Source_Example_CustomTest_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	Example_Source_Example_CustomTest_h_13_INCLASS_NO_PURE_DECLS \
	Example_Source_Example_CustomTest_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXAMPLE_API UClass* StaticClass<class ACustomTest>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Example_Source_Example_CustomTest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
