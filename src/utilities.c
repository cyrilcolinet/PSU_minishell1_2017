/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** utilities functions
*/

# include "my.h"
# include "minishell.h"

char *my_strchr(char *str, char delim)
{
	int i = 0;

	while (i < my_strlen(str) + 1) {
		if (*(str + i) == delim)
			return (str + i);
		i++;
	}
	return (NULL);
}

bool my_str_startswith(char *str1, char *str2)
{
	int i = 0;

	while (str1[i]) {
		if (str1[i] != str2[i])
			return (false);
		i++;
	}

	return (true);
}

char *my_str_join(char *str, char delim)
{
	char *new;
	size_t i = 0;
	size_t str_len = 0;

	if (str == NULL || !delim)
		return (NULL);

	str_len = my_strlen(str);
	new = my_str_configure(str_len + 1);

	if (new == NULL)
		return (NULL);

	while (i < str_len) {
		*(new + i) = *(str + i);
		i++;
	}
	*(new + i) = delim;
	return (new);
}

void my_free_array(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;

	while (arr[i]) {
		free(arr[i]);
	}

	free(arr);
	arr = NULL;
}

param_t *configure_params(void)
{
	param_t *param = malloc(sizeof(*param));

	if (param == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		return (NULL);
	}

	param->env = NULL;

	return (param);
}
