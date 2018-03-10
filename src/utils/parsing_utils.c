/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** parsing_utils functions
*/

# include "minishell.h"

char *join_next_values(char **array)
{
	char *tmp = NULL;

	array++;
	while (*array != NULL) {
		if (tmp == NULL) {
			tmp = *array;
		} else {
			tmp = my_strjoin_char(tmp, '=');
			tmp = my_strjoin(tmp, *array);
		}
		array++;
	}

	return (tmp);
}
