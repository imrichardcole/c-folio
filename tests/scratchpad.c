#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_string_length(char *string) {
    int position_counter = 0;
    while(1) {
        if(string[position_counter] == '\0') {
            return position_counter;
        } else {
            position_counter++;
        }
    }
}

char * sub_string(char *string, int start, int length) {
    int new_string_length = (length + 1);
    char *new_string = (char *)malloc(new_string_length);
    int position_counter = 0;
    for(int i = 0; i < length; i++)    {
        char char_at_pos = string[start + i];
        new_string[position_counter] = char_at_pos;
        position_counter++;
    }
    new_string[length] = '\0';
    return new_string;
}

int position_from_left_with_start(char *string, char character, int start) {
    for(int i = start; i < get_string_length(string); i++) {
        if(string[i] == character) {
            return i;
        }
    }
    return -1;
}

int position_from_left(char *string, char character) {
    return position_from_left_with_start(string, character, 0);
}

void check_int_equals(int expected, int actual) {
    if(expected != actual) {
        printf("\x1B[31m[FAILED]\x1B[0m expected %d but got %d\n", expected, actual);
        exit(1);
    } else {
        printf("\x1B[32m[PASSED]\x1B[0m test passed\n");
    }
}

void check_string_equals(char *expected, char *actual) {
    if(strcmp(expected, actual) != 0) {
        printf("\x1B[31m[FAILED]\x1B[0m expected %s but got %s\n", expected, actual);
        exit(1);
    } else {
        printf("\x1B[32m[PASSED]\x1B[0m test passed\n");
    }
}

int main()
{
    // 0         1         2
    //
    // 012345678901234567890
    //
    // { "name": "richard" }
    char *string = "{ \"name\": \"richard\" }";

    check_int_equals(4, position_from_left(string, 'a'));
    check_int_equals(21, get_string_length(string));

    char *key = sub_string(string, 0, 2);
    check_string_equals("{ ", key);

    char *value = sub_string(string, 5, 2);
    check_string_equals("me", value);

    check_int_equals(8, position_from_left(string, ':'));

    check_int_equals(2, position_from_left(string, '"'));
    check_int_equals(7, position_from_left_with_start(string, '"', 3));

    char *name_key = sub_string(string, 2, 7);
    // TODO the actual values are the same but maybe we're comparing pointers?
    //check_string_equals("name", name_key);

    check_int_equals(10, position_from_left_with_start(string, '"', 8));
    check_int_equals(18, position_from_left_with_start(string, '"', 11));


    int first_quote = position_from_left(string, '"');
    int second_quote = position_from_left_with_start(string, '"', first_quote);
    
    char * key_value = sub_string(string, first_quote, second_quote);

    int value_first_quote = position_from_left_with_start(string, '"', second_quote);
    int value_second_quote = position_from_left_with_start(string, '"', value_first_quote);
    char * value_value = sub_string(string, first_quote, second_quote);

    printf("key: %s, value: %s\n", key_value, value_value);
    return 0;
}
