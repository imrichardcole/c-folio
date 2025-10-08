cmake_minimum_required(VERSION 3.29)

project(c-folio VERSION 0.0.1 LANGUAGES C)

add_subdirectory(json_parser)

if(WIN32)
    add_compile_options(/W4)
endif()

add_executable(scratchpad tests/scratchpad.c)
