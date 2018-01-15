/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell functions
*/

# include "my.h"
# include "minishell.h"

int minishell(char **env)
{
	param_t *param = my_malloc(sizeof(*param));

	my_putstr("$> ");
	signal(SIGINT, control_c);
	param->env = copy_env(env);

	if (param->env == NULL)
		my_puterr("Error during copy of PATH variable.", true);

	free(param);
	return (0);
}