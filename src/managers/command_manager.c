/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** command_manager functions
*/

# include "minishell.h"

int command_executor(char *stdin, shell_t *shell)
{
	int res = 0;
	char **arg = my_strtok(stdin, ' ');

	if (my_strequ(arg[0], "exit"))
		res = exit_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "cd"))
		res = cd_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "env"))
		print_environment(shell);
	else if (my_strequ(arg[0], "setenv"))
		res = setenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "unsetenv"))
		res = unsetenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "printenv"))
		res = printenv_command(stdin, arg, shell);

	my_freetab(arg);
	return (res);
}
