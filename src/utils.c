/*
** EPITECH PROJECT, 2018
** miishell
** File description:
** utils functions
*/

# include "my.h"
# include "minishell.h"

void correct_exit(param_t *param)
{
	int i;

	for (i = 0; i < param->env_size; i++) {
		free(param->env[i]);
	}

	free(param->env);
	free(param);
}

bool str_equals(char *src, char *find)
{
	int len = 0;

	while (*src) {
		if (*src == *find) {
			src++;
			find++;
			len++;

			if (my_strlen(find) == len)
				return (true);
		} else {
			return (false);
		}
	}

	return (false);
}

char **copy_env(char **env, param_t *param)
{
	char **arr = NULL;
	char **tmp = NULL;
	int id = 0;

	for (id = 0; env[id] != NULL; id++) {
		if (str_equals(env[id], "PATH")) {
			arr = my_strtok(env[id], ":");
			tmp = my_strtok(arr[0], "=");

			free(arr[0]);
			arr[0] = my_strdup(tmp[1]);
			param->env_size = my_count_delim_part(env[id], ":");
			free(tmp);

			return (arr);
		}
	}

	return (NULL);
}

param_t *init_struct(void)
{
	param_t *param = my_malloc(sizeof(*param));

	param->env_copy = NULL;
	param->env = NULL;
	param->env_size = 0;
	param->strcat = NULL;
	param->fdesc = -1;
	param->status = -1;

	return (param);
}

void display_cursor(void)
{
	/*stat_t info;
	int res = -1;

	res = stat("./mysh", &info);

	if (res < 0) {
		my_puterr(strerror(errno), false);
		my_puterr("\n", true);
	}*/

	my_putstr("[cyril@cyril-pc] > ");
}