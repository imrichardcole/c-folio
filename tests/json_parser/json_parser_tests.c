#include "json_parser.h"

#include "test_assertions.h"

int main(int argc, char const *argv[])
{
    JSONDocument json = parse("{ \"test\": \"example\" }");
    const char *value = get_value(&json, "test");

    expect_string_equal("example", "foo", "bar");
    expect_string_equal("another_example", "bar", "bar");
    expect_string_equal("final_example", value, "example");
    return 0;
}
