/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** parsing_utils functions
*/

# include "minishell.h"

char *realloc_char(char *ptr, unsigned int size)
{
	char *new_ptr = my_strconfigure(size);
	int ch = 0;

	if (ptr == NULL || size < 1 || !new_ptr)
		return (NULL);
	while (((ssize_t)ch) != size && ptr[ch] != '\0') {
		new_ptr[ch] = ptr[ch];
		ch++;
	}
	if (ptr[ch])
		while (((ssize_t)ch) < size)
			new_ptr[ch++] = 0;
	new_ptr[ch] = 0;
	free(ptr);
	return (new_ptr);
}

char *join_next_values(char **array)
{
	char *str = NULL;

	array++;
	while (*array != NULL) {
		if (str == NULL) {
			str = my_strdup(*array);
		} else {
			str = realloc_char(str, my_strlen(str) + 1);
			str = my_strjoin_clear(str, "=", false);
			str = realloc_char(str, my_strlen(str) + my_strlen(*array));
			str = my_strjoin_clear(str, *array, false);
		}
		array++;
	}
	return (str);
}

char *path_join(char *str1, char *str2)
{
	char *tmp2 = NULL;

	if (!str1 || !str2)
		return (NULL);
	if (!my_strendswith(str1, "/")) {
		if (str2[0] == '/') {
			return (my_strjoin(str1, str2));
		} else {
			tmp2 = my_strjoin_clear(my_strjoin_char(str1, '/'), str2, 0);
			return (tmp2);
		}
	}

	if (str2[0] == '/') {
		return (my_strjoin(str1, str2 + 1));
	}

	return (my_strjoin(str1, str2));
}
