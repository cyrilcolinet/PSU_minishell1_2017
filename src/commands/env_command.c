/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** env_command functions
*/

# include "my.h"
# include "minishell.h"

int env_command(char *stdin, char *command, char **env)
{
	int i = -1;

	while (env[i]) {
		my_printf("%s\n", env[i]);
		i++;
	}

	return (0);
}