# This is dummy CMake file for CLion project.

set(PROJECT_NAME k2)

cmake_minimum_required(VERSION 3.28)
project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 11)

include_directories(C:/SDK/cc65/include)

file(GLOB_RECURSE SOURCES "*.c")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE __TARGET_nes __PORT_mos6502)
