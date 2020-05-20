#include <criterion/criterion.h>
#include "brainfuck2.h"
#include "instructions.h"

Test(add, basic)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);

    cr_assert_not_null(memory);
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    cr_assert_eq(add(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], 1);
    memory->tape_ptr = 10;
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    cr_assert_eq(add(memory), EXIT_SUCCESS);
    cr_assert_eq(add(memory), EXIT_SUCCESS);
    cr_assert_eq(add(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], 3);
    memory_destroy(memory);
}

Test(sub, basic)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);

    cr_assert_not_null(memory);
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    cr_assert_eq(sub(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], (unsigned char)-1);
    memory->tape_ptr = 10;
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    cr_assert_eq(sub(memory), EXIT_SUCCESS);
    cr_assert_eq(sub(memory), EXIT_SUCCESS);
    cr_assert_eq(sub(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], (unsigned char)-3);
    memory_destroy(memory);
}

Test(add_and_sub, basic)
{
    mem_t *memory = memory_create(DEFAULT_TAPE_SIZE);

    cr_assert_not_null(memory);
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    cr_assert_eq(sub(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], (unsigned char)-1);
    cr_assert_eq(add(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    cr_assert_eq(add(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], 1);
    cr_assert_eq(sub(memory), EXIT_SUCCESS);
    cr_assert_eq(memory->tape[memory->tape_ptr], 0);
    memory_destroy(memory);
}

