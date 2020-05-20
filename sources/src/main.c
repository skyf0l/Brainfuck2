#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck2.h"
#include "strings.h"

int main(int ac, char const **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        printf(HELP);
        return (EXIT_SUCCESS);
    }
    if (ac == 1)
        return (interactive_console());
    return (file_interpretor(av[1]));
}
