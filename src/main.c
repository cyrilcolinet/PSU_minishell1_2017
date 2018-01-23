/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main function
*/

# include "minishell.h"

int main(int ac, char **av, char **env)
{
	int res = minishell(ac, av, env);

	return (res);
}