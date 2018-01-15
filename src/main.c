/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Main function
*/

# include "my.h"
# include "minishell.h"

int main(int ac, char **av, char **env)
{
	int res;

	if (ac == 1 && str_equals(av[0], "./mysh")) {
		res = minishell(env);
		return (res);
	}

	my_puterr("Too much argument or false binary name.", false);
	return (84);
}