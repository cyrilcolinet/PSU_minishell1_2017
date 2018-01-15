/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** controls functions
*/

# include "my.h"
# include "minishell.h"

void control_c(void)
{
	my_putchar('\n');
	my_putstr("$> ");
}

void control_exit(char *buff)
{
	char *res = my_strstr("exit", buff);

	if (res == 0) {
		exit(0);
	}
}