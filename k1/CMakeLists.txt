# This is dummy CMake file for CLion project.

cmake_minimum_required(VERSION 3.28)
project(k1 C)

set(CMAKE_C_STANDARD 11)

include_directories(C:/SDK/gbdk/include)

add_library(k1 STATIC
        main.c)

target_compile_definitions(k1 PRIVATE __TARGET_nes __PORT_mos6502)
