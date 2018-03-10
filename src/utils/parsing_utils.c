/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** parsing_utils functions
*/

# include "minishell.h"

char *join_next_values(char **array)
{
	char *str = NULL;

	array++;
	while (*array != NULL) {
		if (str == NULL) {
			str = my_strdup(*array);
		} else {
			str = my_strjoin(str, "=");
			str = my_strjoin_clear(str, *array, false);
		}
		array++;
	}
	return (str);
}
