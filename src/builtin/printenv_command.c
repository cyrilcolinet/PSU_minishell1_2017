/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** printenv_command functions
*/

# include "minishell.h"

int printenv_command(char *stdin, char **arg, shell_t *shell)
{
	char *content = NULL;
	(void)stdin;

	if (!arg[1]) {
		my_putstr("printenv: Too few arguments\n");
		return (0);
	}

	content = env_get_variable(arg[1], shell);

	if (content) {
		my_putstr(content);
		my_putstr("\n");
	}

	return (0);
}
