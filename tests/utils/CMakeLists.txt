add_library(test_utils STATIC test_assertions.h test_assertions.c)

target_include_directories(test_utils
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)