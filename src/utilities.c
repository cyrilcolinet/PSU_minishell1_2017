/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** utilities functions
*/

# include "my.h"
# include "minishell.h"

char *my_str_join(char *str1, char *str2)
{
	char *new;
	size_t i = 0, j = 0, str1len = 0, str2len = 0;

	if (str1 == NULL || str2 == NULL)
		return (NULL);

	str1len = my_strlen(str1);
	str2len = my_strlen(str2);
	new = my_str_configure(str1len + str2len + 1);

	if (new == NULL)
		return (NULL);

	while (i++ < str1len)
		*(new + i) = *(str1 + i);
	while (j++ < str2len)
		*(new + i++) = *(str2 + j);
	return (new);
}

char *my_str_joincl(char *str1, char *str2, int free_both)
{
	char *new = my_str_join(str1, str2);

	if (new == NULL)
		return (NULL);

	free(str1);
	str1 = NULL;

	if (free_both) {
		free(str2);
		str2 = NULL;
	}
	return (new);
}

bool my_str_endswith(char *str1, char *str2)
{
	int i = 0;

	while (str1[i]) {
		if (str1[i] == *str2)
			if (my_strcmp(str1 + i, str2) == 0)
				return (true);
		i++;
	}
	return (false);
}

char *my_str_joinch(char *str, char delim)
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

char *my_pathjoin(char *str1, char *str2)
{
	char *tmp2;

	if (str2 == NULL || str1 == NULL)
		return (NULL);

	if (!my_str_endswith(str1, "/")) {
		if (*str2 == '/') {
			return (my_str_join(str1, str2));
		} else {
			tmp2 = my_str_joincl(my_str_joinch(str1, '/'), str2, 0);
			return (tmp2);
		}
	}

	return (my_str_join(str1, (*str2 == '/') ? str2 + 1 : str2));
}

// Lot offunctions, move functions before in another source file

char *my_strchr(char *str, char delim)
{
	int i = 0;

	while (i < my_strlen(str) + 1) {
		if (*(str + i) == delim)
			return ((char *)str + i);
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
	param->exit_sts = 0;

	return (param);
}
