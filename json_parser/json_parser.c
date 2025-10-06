#include "json_parser.h"

#include <string.h>
#include <stdio.h>

JSONDocument parse(const char* contents) {
    JSONDocument doc;
    char *opening = strchr(contents, '"');
    char *closing = strchr(opening + 1, '"');

    int opening_index = (int)(opening - contents + 1);
    int closing_index = (int)(closing - contents + 1);

    int length = closing_index - opening_index;

    char substring[20];
    strncpy_s(substring, contents + opening_index, length, 4);
    substring[length] = '\0';
    return doc;
}

const char* get_value(JSONDocument *json, const char* key) {
    return "example";
}