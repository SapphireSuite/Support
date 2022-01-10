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
