#include <stdlib.h>
#include "brainfuck2.h"

int conditional_in(mem_t *mem)
{
    int conditional_layer = 0;

    if (mem->tape[mem->tape_ptr])
        return (EXIT_SUCCESS);
    while (mem->script.ops[mem->script.op_id]) {
        ++(mem->script.op_id);
        if (mem->script.ops[mem->script.op_id] == '!') 
            --conditional_layer;
        else if (mem->script.ops[mem->script.op_id] == '?')
            ++(conditional_layer);
        else if (conditional_layer == 0 && mem->script.ops[mem->script.op_id] == ':')
            return (EXIT_SUCCESS);
        else if (!mem->script.ops[mem->script.op_id]) {
            --(mem->script.op_id);
            return (EXIT_SUCCESS);
        }
    }
    return (EXIT_SUCCESS);
}

int conditional_mid(mem_t *mem)
{
    int conditional_layer = -1;

    if (mem->tape[mem->tape_ptr])
        return (EXIT_SUCCESS);
    while (conditional_layer != 0 && mem->script.ops[mem->script.op_id]) {
        ++(mem->script.op_id);
        if (mem->script.ops[mem->script.op_id] == '!') 
            ++conditional_layer;
        else if (mem->script.ops[mem->script.op_id] == '?')
            --(conditional_layer);
        else if (!mem->script.ops[mem->script.op_id]) {
            --(mem->script.op_id);
            return (EXIT_SUCCESS);
        }
    }
    return (EXIT_SUCCESS);
}

int conditional_out(mem_t *mem)
{
    return (EXIT_SUCCESS);
    (void)mem;
}