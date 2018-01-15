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
	while (*src) {
		if (*src == *find) {
			src++;
			find++;
		} else {
			return (false);
		}
	}

	return (true);
}

char **copy_env(char **env)
{
	char **arr = NULL;
	int off = 0;

	while (arr[off]) {
		if (str_equals(env[off], "PATH"))
			arr = my_strtok(env[off], ":");

		off++;
	}

	return (arr);
}