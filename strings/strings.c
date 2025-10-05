#include <string.h>

size_t get_string_length(const char *string)
{
    return strlen(string);
}

const char *get_sub_string(const char *string, int start, int length)
{
    static char buffer[256];
    strncpy_s(buffer, 256, string + start, length);
    buffer[length] = '\0';
    return buffer;
}

int get_index_of(const char *string, char character, int start)
{
    for (int i = start; i < get_string_length(string); i++)
    {
        const char current_char = string[i];
        if (current_char == character)
        {
            return i;
        }
    }
    return -1;
}