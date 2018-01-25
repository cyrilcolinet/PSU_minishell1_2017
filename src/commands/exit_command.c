/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** exit_command functions
*/

# include "my.h"
# include "minishell.h"

int exit_command(char **command, param_t *param)
{
	int count = 0;

	if (command == NULL)
		return (-1);

	while (command[count])
		count++;

	if (count < 2) {
		param->exit_sts = 0;
	} else if (count > 2) {
		my_putstr("Error: Too many arguments (exit).\n\n");
		return (1);
	} else if (count == 2) {
		if (!my_str_isnum(command[1], false)) {
			my_putstr("Error: Exit status must be a number.\n\n");
			return (1);
		}

		param->exit_sts = my_atoi(command[1]);
	}

	return (-1);
}