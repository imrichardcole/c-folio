#include "json_parser.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void print_success(const char* message) {
    printf("\x1b[32m[SUCCESS]\x1b[0m %s\n", message);
}

void print_failure(const char* message) {
    printf("\x1b[31m[FAILURE]\x1b[0m %s\n", message);
}

void expect_equal(const char* value, const char* expected) {
    int are_equal = strcmp(value, expected);
    if (are_equal < 0 || are_equal > 0) {
        print_failure("Strings are not equal");
    }
    else {
        print_success("Strings are equal");
    }
}

int main(int argc, char const *argv[])
{
    JSONDocument json = parse("{ \"test\": \"example\" }");
    const char *value = get_value(&json, "test");

    expect_equal("foo", "bar");
    expect_equal("bar", "bar");
    expect_equal(value, "example");
    return 0;
}
