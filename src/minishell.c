/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions
*/

# include "minishell.h"

int main_minishell(int ac, char **av, char **env)
{
	shell_t *shell = configure(env);

	if (shell == NULL)
		return (84);
	return (0);
}
