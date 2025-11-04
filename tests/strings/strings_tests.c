#include "strings.h"
#include "test_assertions.h"

#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const char *string_content = "Hello, world!";
    size_t length = get_string_length(string_content);
    expect_equal("get_string_length", length, 13);
    expect_not_equal("get_string_length_not_equal", length, 1024);

    const char *sub_string = get_sub_string(string_content, 0, 5);
    expect_equal("get_string_length_via_substring", get_string_length(sub_string), 5);
    expect_string_equal("get_sub_string", sub_string, "Hello");

    const char *another_sub_string = get_sub_string(string_content, 5, 2);
    expect_equal("get_string_length_via_substring_non_zero_start", get_string_length(another_sub_string), 2);
    expect_string_equal("get_sub_string_non_zero_start", sub_string, ", ");

    const char *sub_string_beyond_length = get_sub_string(string_content, 10, 15);
    expect_equal("get_string_length_via_substring_beyond_length", get_string_length(another_sub_string), 3);
    expect_string_equal("get_sub_string_beyond_string_length", sub_string, "ld!");

    int index = get_index_of(string_content, ',', 0);
    expect_equal("index_of", index, 5);
    return 0;
}
