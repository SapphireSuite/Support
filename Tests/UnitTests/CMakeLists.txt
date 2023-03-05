# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

SA_FetchGoogleTest()



# Executable

## Inputs

file(GLOB_RECURSE SA_SUPPORT_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_SupportUT ${SA_SUPPORT_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SupportUT PRIVATE SA_Support)

### Google test module dependency.
target_link_libraries(SA_SupportUT PRIVATE gtest)



# Tests

add_test(NAME CSA_SupportUT COMMAND SA_SupportUT)
