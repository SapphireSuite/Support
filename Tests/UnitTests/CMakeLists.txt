# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SupportUT)

SA_FetchGoogleTest()



# Executable

## Inputs

file(GLOB_RECURSE SA_SUPPORT_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_SupportUT ${SA_SUPPORT_UT_SOURCES})



## Compile features

### Standard
target_compile_features(SA_SupportUT PUBLIC c_std_11)
target_compile_features(SA_SupportUT PUBLIC cxx_std_20)



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SupportUT PRIVATE SA_Support)

### Google test module dependency.
target_link_libraries(SA_SupportUT PRIVATE gtest)



# Tests

add_test(NAME CSA_SupportUT COMMAND SA_SupportUT)
