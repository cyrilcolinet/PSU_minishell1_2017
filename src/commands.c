/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** commands functions
*/

# include "my.h"
# include "minishell.h"

void command_exit(char *buffer)
{
	if (str_equals(buffer, "exit"))
		exit(0);
}

void command_basics(param_t *param)
{
	int ret = execve(param->strcat, param->arg, param->env_copy);

	if (ret == -1)
		exit(84);
}