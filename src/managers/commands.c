/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** commands manager functions
*/

# include "my.h"
# include "minishell.h"

bool check_binaries(char **command)
{
	return (true);
}

bool is_own_command(char **command)
{
	return (true);
}

int exec_command(char **command)
{
	stat_t info;
	bool own_func = is_own_command(command);

	if (own_func || check_binaries(command))
		return (0);

	return (0);
}