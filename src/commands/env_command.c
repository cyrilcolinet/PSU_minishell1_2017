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

int setenv_command(char *stdin, param_t *param)
{
	char **args = my_strtok(stdin, ' ');

	printf("bbbb\n");

	if (!args[0]) {
		if (args != NULL)
			my_free_array(args);

		return (env_command(stdin, param));
	}

	if (args[1] && args[2]) {
		my_putstr("Error: Too many arguments (setenv).\n");
		return (1);
	}

	//setenvvar
	return (1);
}