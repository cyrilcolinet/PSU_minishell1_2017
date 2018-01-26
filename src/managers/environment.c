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
	int key = 0;
	int count = 0;

	while (env[key]) {
		count++;
		key++;
	}

	return (count);
}

void env_configure(char **env, param_t *param)
{
	int key = 0;
	int envlen = env_length(env);

	param->env = malloc(sizeof(*param->env) * (envlen + 1));

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

		key++;
	}

	param->env[key] = NULL;
}

char *env_get_var(char *variable, char **env)
{
	int i = 0;
	char *tmp;

	while (env[i]) {
		tmp = my_str_joinch(variable, '=');

		if (my_str_startswith(env[i], tmp)) {
			free(tmp);
			return (my_strchr(env[i], '=') + 1);
		}

		free(tmp);
		i++;
	}

	return (NULL);
}