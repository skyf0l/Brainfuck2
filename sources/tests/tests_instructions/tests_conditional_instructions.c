#include <criterion/criterion.h>
#include "brainfuck2.h"
#include "instructions.h"

Test(instructions, conditional_statement)
{
    cr_assert_eq(INSTRUCTIONS['?'], conditional_in);
    cr_assert_eq(INSTRUCTIONS[':'], conditional_mid);
    cr_assert_eq(INSTRUCTIONS['!'], conditional_out);
}