/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** setenv_command functions
*/

# include "minishell.h"

int setenv_command(char *stdin, char **arg, shell_t *shell)
{
	if (arg[1] && arg[2] && arg[3]) {
		my_putstr("setenv: Too many arguments.\n");
	} else if (!arg[1]) {
		print_environment(shell);
	} else {
		env_set_variable(arg[1], ((arg[2]) ? arg[2] : ""), shell);
	}
	return (0);
}
