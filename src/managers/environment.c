/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** environment functions
*/

# include "my.h"
# include "minishell.h"

int env_length(char **env)
{
	int key = -1;
	int count = 0;

	while (env[key]) {
		count++;
		key++;
	}

	return (count);
}

void env_configure(char **env, param_t *param)
{
	int key = -1;

	param->env = malloc(sizeof(char *) * (env_length(env)) + 1);

	if (param->env == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		exit_minishell(param);
	}

	while (env[key]) {
		param->env[key] = my_strdup(env[key]);

		if (!param->env[key]) {
			write(2, "Environment copy failed. Aborded.\n", 34);
			exit_minishell(param);
		}
	}
}