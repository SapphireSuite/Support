# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)



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
option(SA_SUPPORT_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)


# Entrypoints

if(SA_SUPPORT_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)

endif()



# Helper Functions

function(SA_SetupIntrinsicsFlags _target _linkOpt)

	if("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")

		target_compile_options(${_target} ${_linkOpt} /arch:AVX2)

	else()

		target_compile_options(${_target} ${_linkOpt} -mavx -mavx2)

	endif()

endfunction()
