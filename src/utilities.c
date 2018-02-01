/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** utilities functions
*/

# include "my.h"
# include "minishell.h"

char *my_pathjoin(char *str1, char *str2)
{
	char *tmp2;

	if (str2 == NULL || str1 == NULL)
		return (NULL);

	if (!my_strendswith(str1, "/")) {
		if (*str2 == '/') {
			return (my_strjoin(str1, str2));
		} else {
			tmp2 = my_strjoin_clear(my_strjoin_char(str1, '/'), str2, 0);
			printf("tmp2 = %s\n", tmp2);
			return (tmp2);
		}
	}

	return (my_strjoin(str1, (*str2 == '/') ? str2 + 1 : str2));
}

param_t *configure_params(int fd)
{
	param_t *param = malloc(sizeof(*param));

	if (param == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		return (NULL);
	}

	param->env = NULL;
	param->environment = NULL;
	param->exit_sts = 0;
	param->path = NULL;
	param->fdesc = fd;

	return (param);
}
