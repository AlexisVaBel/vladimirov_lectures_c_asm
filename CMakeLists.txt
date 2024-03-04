cmake_minimum_required(VERSION 3.26)
project(custom_assembler C)

set(CMAKE_C_STANDARD 17)

include_directories("C:/tools/GnuWin32/include")
link_directories("C:/tools/GnuWin32/lib")


add_executable(custom_assembler main.c
        Commands.h
        Commands.c
        Registers.h
        RegexpForCommand.h
        RegexpForCommand.c)

target_link_libraries(custom_assembler regex.lib)
