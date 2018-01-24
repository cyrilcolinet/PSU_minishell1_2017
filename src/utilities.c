/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** utilities functions
*/

# include "my.h"
# include "minishell.h"

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
