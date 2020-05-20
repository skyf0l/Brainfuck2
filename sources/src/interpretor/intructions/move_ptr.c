#include <stdlib.h>
#include "brainfuck2.h"

int move_ptr_right(mem_t *memory)
{
    ++(memory->tape_ptr);
    if (memory->tape_ptr == memory->tape_size)
        memory->tape_ptr = 0;
    return (EXIT_SUCCESS);
}

int move_ptr_left(mem_t *memory)
{
    if (memory->tape_ptr == 0)
        memory->tape_ptr = memory->tape_size;
    --(memory->tape_ptr);
    return (EXIT_SUCCESS);
}