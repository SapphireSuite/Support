# Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

# Executable

## Add executable target.
add_executable(SA_SupportProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SupportProto PRIVATE SA_Support)



# Tests

add_test(NAME CSA_SupportProto COMMAND SA_SupportProto)
