/*
** EPITECH PROJECT, 2020
** TESTS_READ_FILE
** File description:
** Test read_file
*/

#include <criterion/criterion.h>

unsigned char *read_file(const char *file_path);

Test(read_file, unexist_file)
{
    char *path = "tests/files/unexist";
    char *content = (char *)read_file(path);

    cr_assert_null(content);
}

Test(read_file, permission_denied)
{
    char *path = "/dev/tty1";
    char *content = (char *)read_file(path);

    cr_assert_null(content);
}

Test(read_file, basic_file)
{
    char *path = "tests/files/cat.bf";
    char *content = (char *)read_file(path);

    cr_assert_not_null(content);
    cr_assert_str_eq(content, ",[.,]");
    free(content);
}