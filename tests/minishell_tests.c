/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell unitary tests
*/

# include "minishell.h"
# include <criterion/criterion.h>
# include <criterion/redirect.h>

void redirect_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(minishell, one, .init = redirect_std)
{
	int res = minishell();

	cr_assert_stdout_eq(res);
}