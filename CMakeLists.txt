# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)

# Sapphire Suite's CMake tools.
add_subdirectory(ThirdParty/SA/CMake)



# Project

project(SA_Support)
SA_ConfigureProject(SA_Support)



# Library

add_library(SA_Support INTERFACE)

SA_ConfigureTarget(SA_Support LINK INTERFACE)
SA_TargetInterfaceSources(SA_Support)



# Options

## Add SA_Support's tests to build tree.
option(SA_SUPPORT_BUILD_TESTS_OPT "Should build SA_Support tests" OFF)



# Entrypoints

if(SA_SUPPORT_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)

endif()
