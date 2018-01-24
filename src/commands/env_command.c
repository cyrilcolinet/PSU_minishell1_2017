/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** env_command functions
*/

# include "my.h"
# include "minishell.h"

int env_command(char *stdin, param_t *param)
{
	int i = 0;

	while (param->env[i]) {
		my_putstr(param->env[i]);
		my_putstr("\n");
		i++;
	}

	my_putstr("\n");

	return (1);
}