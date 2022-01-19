# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SupportUT)



# Fetch Google Test.
if(NOT TARGET gtest)

	message("Fetching Google Test...")

	include(FetchContent)

	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG        release-1.11.0
	)

	FetchContent_MakeAvailable(googletest)

endif()



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
