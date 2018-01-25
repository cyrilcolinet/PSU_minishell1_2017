/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** env_command functions
*/

# include "my.h"
# include "minishell.h"

int env_command(char **command, param_t *param)
{
	int i = 0;
	(void)command;

	while (param->env[i]) {
		my_putstr(param->env[i]);
		my_putstr("\n");
		i++;
	}

	my_putstr("\n");

	return (1);
}

int setenv_command(char **command, param_t *param)
{
	int count = 0;

	if (!command[1]) {
		return (env_command(command, param));
	}

	while (command[count])
		count++;

	if (count != 3) {
		my_putstr("Error: Too much or less arguments (setenv).\n");
		return (1);
	}

	//setenvvar
	return (1);
}