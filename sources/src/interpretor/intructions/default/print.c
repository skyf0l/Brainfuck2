#include <stdlib.h>
#include <unistd.h>
#include "brainfuck2.h"

int print_char(mem_t *memory)
{
    write(1, &(memory->tape[memory->tape_ptr]), 1);
    return (EXIT_SUCCESS);
}