#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck2.h"

mem_t *memory_create(uint tape_size)
{
    mem_t *memory = malloc(sizeof(mem_t));

    if (!memory)
        return (NULL);
    memory->script.ops = NULL;
    memory->script.op_id = 0;
    memory->tape_ptr = 0;
    memory->tape_size = tape_size;
    memory->tape = malloc(sizeof(unsigned char) * (tape_size));
    if (!memory->tape)
        return (memory_destroy(memory));
    memset(memory->tape, 0, tape_size);
    return (memory);
}

void *memory_destroy(mem_t *memory)
{
    if (!memory)
        return (NULL);
    if (memory->tape)
        free(memory->tape);
    free(memory);
    return (NULL);
}