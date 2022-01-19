# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


### Add Max warning level for tests.
if(MSVC)

	if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") # ClangCl

		target_compile_options(SA_Support INTERFACE -W4)

	else()

		target_compile_options(SA_Support INTERFACE /W4)

	endif()

else()

	target_compile_options(SA_Support INTERFACE -Wall -Wextra)

endif()



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)
