add_library(json_parser json_parser.h json_parser.c)

target_compile_options(json_parser PRIVATE
  /W4
)

target_include_directories(json_parser
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(json_parser_tests ../tests/json_parser/json_parser_tests.c)

target_link_libraries(json_parser_tests json_parser)