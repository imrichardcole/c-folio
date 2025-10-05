add_library(strings strings.h strings.c)

target_compile_options(strings PRIVATE
  /W4
)

target_include_directories(strings
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(strings_tests ../tests/strings/strings_tests.c)

target_link_libraries(strings_tests strings)


