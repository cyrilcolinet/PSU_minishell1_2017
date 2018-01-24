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

	param->env[envlen - 1] = NULL;
}

char *env_get_variable(char *variable, char **env)
{
	int i = -1;
	int len;
	char *tmp;
	char **toktmp;

	while (env[i]) {
		len = my_strlen(env[i]) + 2;
		tmp = malloc(sizeof(*tmp) * len);

		if (tmp == NULL)
			return (NULL);

		tmp[len - 2] = '=', tmp[len - 1] = 0;

		//if (my_str_startwith(env[i], tmp)) {
		if (false && variable[0]) {
			free(tmp);
			toktmp = my_strtok(env[i], "=");
			return (toktmp[1]);
		}

		free(tmp);
	}

	return (NULL);
}