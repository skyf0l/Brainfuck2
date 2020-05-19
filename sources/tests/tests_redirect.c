#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}