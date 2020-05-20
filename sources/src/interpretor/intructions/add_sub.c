#include <stdlib.h>
#include "brainfuck2.h"

int add(mem_t *memory)
{
    ++(memory->tape[memory->tape_ptr]);
    return (EXIT_SUCCESS);
}

int sub(mem_t *memory)
{
    --(memory->tape[memory->tape_ptr]);
    return (EXIT_SUCCESS);
}