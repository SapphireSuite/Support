# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.17)



# Project

project(SA_Support)

message("SA_Maths Main directory: ${CMAKE_SOURCE_DIR}")



# Library

## Interface library.
add_library(SA_Support INTERFACE)

## Include directories
target_include_directories(SA_Support INTERFACE Include)

### SA_Support module implementation preprocessor.
target_compile_definitions(SA_Support INTERFACE SA_SUPPORT_IMPL)



# Options

## Add SA_Maths's tests to build tree.
option(SA_SUPPORT_INTRINSICS_FLAGS_OPT "Should link intrinsics compile flags" ON)

if(SA_SUPPORT_INTRINSICS_FLAGS_OPT)

	if("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")

		target_compile_options(SA_Support INTERFACE /arch:AVX2)

	else()

		target_compile_options(SA_Support INTERFACE -mavx -mavx2)

	endif()

endif()



# Helper Functions

## Max warning level (for testing).
function(SA_SetupMaxWarningLevel _target)

	if(MSVC)

		if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") # ClangCl

			target_compile_options(${_target} PUBLIC -W4)

		else()

			target_compile_options(${_target} PUBLIC /W4)

		endif()

	elseif()

		target_compile_options(${_target} PUBLIC -Wall -Wextra)

	endif()
	
endfunction()

