#include <stdlib.h>
#include <unistd.h>
#include "brainfuck2.h"

int while_in(mem_t *mem)
{
    int while_layer = -1;

    if (mem->tape[mem->tape_ptr])
        return (EXIT_SUCCESS);
    while (while_layer != 0 && mem->script.ops[mem->script.op_id]) {
        ++(mem->script.op_id);
        if (mem->script.ops[mem->script.op_id] == ']')
            ++while_layer;
        else if (mem->script.ops[mem->script.op_id] == '[')
            --(while_layer);
    }
    return (EXIT_SUCCESS);
}

int while_out(mem_t *mem)
{
    int while_layer = -1;

    if (!mem->tape[mem->tape_ptr])
        return (EXIT_SUCCESS);
    while (while_layer != 0 && mem->script.ops[mem->script.op_id]) {
        --(mem->script.op_id);
        if (mem->script.ops[mem->script.op_id] == '[')
            ++while_layer;
        else if (mem->script.ops[mem->script.op_id] == ']')
            --while_layer;
    }
    return (EXIT_SUCCESS);
}