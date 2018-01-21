/*
** EPITECH PROJECT, 2018
** miishell
** File description:
** utils functions
*/

# include "my.h"
# include "minishell.h"

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

char **copy_env(char **env)
{
	char **arr = NULL;
	char **tmp = NULL;
	int id = 0;

	for (id = 0; env[id] != NULL; id++) {
		if (str_equals(env[id], "PATH")) {
			arr = my_strtok(env[id], ":");
			tmp = my_strtok(arr[0], "=");
			printf("%s\n", tmp[0]);
			//arr[0] = tmp[0][1];
			return (arr);
		}
	}

	return (NULL);
}