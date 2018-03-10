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

char **separate_environment(char *env)
{
	int eq_pos = 0;
	int i = 0;
	char *cpy = env;
	char **arr = malloc(sizeof(char *) * 3);

	while (*cpy != '=') {
		eq_pos++;
		cpy++;
	}

	cpy = env;
	arr[0] = my_strconfigure(eq_pos);
	while (*cpy != '=') {
		arr[0][i] = env[i++];
		cpy++;
	}
	printf("env: %s\n pos: %d\n var: %s\n", env, eq_pos, arr[0]);
	return (NULL);
}
