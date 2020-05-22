#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck2.h"
#include "instructions.h"

int interpretor(unsigned char *instructions)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);

    if (!memory) {
        fprintf(stderr, "bf2: malloc failed.\n");
        return (EXIT_FAILURE);
    }
    memory->script.ops = instructions;
    while (instructions[memory->script.op_id]) {
        INSTRUCTIONS[instructions[memory->script.op_id]](memory);
        ++(memory->script.op_id);
    }
    memory_destroy(memory);
    return (EXIT_SUCCESS);
}