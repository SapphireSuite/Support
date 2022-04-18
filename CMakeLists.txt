# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)



# Project

project(SA_Support)

message("SA_Support Main directory: ${CMAKE_CURRENT_SOURCE_DIR}")



# Library

## Input.
file(GLOB_RECURSE SA_SUPPORT_SOURCES "Source/*")

## Static library.
add_library(SA_Support STATIC ${SA_SUPPORT_SOURCES})

## Include directories
target_include_directories(SA_Support PUBLIC Include)

## Compile features

### Standard
target_compile_features(SA_Support PUBLIC c_std_11)
target_compile_features(SA_Support PUBLIC cxx_std_20)

### SA_Support module implementation preprocessor.
target_compile_definitions(SA_Support PUBLIC SA_SUPPORT_IMPL)



# Options

## Add SA_Maths's tests to build tree.
option(SA_SUPPORT_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)


# Entrypoints

add_subdirectory(ThirdParty)

if(SA_SUPPORT_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)

endif()

