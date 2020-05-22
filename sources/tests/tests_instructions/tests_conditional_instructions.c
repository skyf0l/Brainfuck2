#include <criterion/criterion.h>
#include "brainfuck2.h"
#include "instructions.h"

Test(instructions, conditional_statement)
{
    cr_assert_eq(INSTRUCTIONS['?'], conditional_in);
    cr_assert_eq(INSTRUCTIONS[':'], conditional_mid);
    cr_assert_eq(INSTRUCTIONS['!'], conditional_out);
}

Test(conditional_in, basic_true)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:!";

    cr_assert_not_null(memory);
    add(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 0);
    memory_destroy(memory);
}

Test(conditional_in, basic_false)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:!";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 1);
    memory_destroy(memory);
}

Test(conditional_in, eof_false_1)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 0);
    memory_destroy(memory);
}

Test(conditional_in, eof_false_2)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?+";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 1);
    memory_destroy(memory);
}

Test(conditional_in, multi_false_1)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"??:!:!+";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 4);
    memory_destroy(memory);
}

Test(conditional_in, multi_false_2)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"???:!:?:!!?:!:!+";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 13);
    memory_destroy(memory);
}

Test(conditional_in, no_mid_1)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?!+";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 1);
    memory_destroy(memory);
}

Test(conditional_in, no_mid_2)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?+?:!!+";

    cr_assert_not_null(memory);
    cr_assert_eq(conditional_in(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 5);
    memory_destroy(memory);
}

Test(conditional_mid, basic)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:!";

    cr_assert_not_null(memory);
    memory->script.op_id = 1;
    cr_assert_eq(conditional_mid(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 2);
    memory_destroy(memory);
}

Test(conditional_mid, multi_1)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:?:!!";

    cr_assert_not_null(memory);
    memory->script.op_id = 1;
    cr_assert_eq(conditional_mid(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 5);
    memory_destroy(memory);
}

Test(conditional_mid, multi_2)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"!?:??:?:!!:?:!!!+";

    cr_assert_not_null(memory);
    memory->script.op_id = 2;
    cr_assert_eq(conditional_mid(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 15);
    memory_destroy(memory);
}

Test(conditional_mid, eof_1)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:";

    cr_assert_not_null(memory);
    memory->script.op_id = 1;
    cr_assert_eq(conditional_mid(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 1);
    memory_destroy(memory);
}

Test(conditional_mid, eof_2)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:+";

    cr_assert_not_null(memory);
    memory->script.op_id = 1;
    cr_assert_eq(conditional_mid(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 2);
    memory_destroy(memory);
}

Test(conditional_out, basic)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);
    memory->script.ops = (unsigned char *)"?:!+";

    cr_assert_not_null(memory);
    memory->script.op_id = 2;
    cr_assert_eq(conditional_out(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->script.op_id, 2);
    memory_destroy(memory);
}