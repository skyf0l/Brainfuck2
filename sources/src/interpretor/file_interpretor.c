#include <stdio.h>
#include <stdlib.h>
#include "brainfuck2.h"

int file_interpretor(char const *file_path)
{
    int rtn_value;
    unsigned char *file_content = read_file(file_path);

    if (!file_content)
        return (EXIT_FAILURE);
    rtn_value = interpretor(file_content);
    free(file_content);
    return (rtn_value);
}