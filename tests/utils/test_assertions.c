
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_success(const char *message)
{
    printf("\x1b[32m[SUCCESS]\x1b[0m %s\n", message);
}

void print_failure(const char *message)
{
    printf("\x1b[31m[FAILURE]\x1b[0m %s\n", message);
}

void expect_equal(const char *test_name, const size_t value, const size_t expected)
{
    if (value != expected)
    {
        char buffer[100];
        sprintf_s(buffer, 100, "[%s] values are not equal - expected %zu but got %zu", test_name, expected, value);
        print_failure(buffer);
    }
    else
    {
        char buffer[100];
        sprintf_s(buffer, 100, "[%s] values are equal", test_name);
        print_success(buffer);
    }
}

void expect_not_equal(const char *test_name, const size_t value, const size_t expected)
{
    if (value == expected)
    {
        char buffer[100];
        sprintf_s(buffer, 100, "[%s] values are equal - expected %zu to not equal %zu", test_name, expected, value);
        print_failure(buffer);
    }
    else
    {
        char buffer[100];
        sprintf_s(buffer, 100, "[%s] values are not equal", test_name);
        print_success(buffer);
    }
}

void expect_string_equal(const char *test_name, const char *value, const char *expected)
{
    if (strcmp(value, expected) != 0)
    {
        char buffer[100];
        sprintf_s(buffer, 100, "[%s] strings are not equal - expected '%s' but got '%s'", test_name, expected, value);
        print_failure(buffer);
    }
    else
    {
        char buffer[100];
        sprintf_s(buffer, 100, "[%s] strings are equal", test_name);
        print_success(buffer);
    }
}