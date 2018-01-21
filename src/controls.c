/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** controls functions
*/

# include "my.h"
# include "minishell.h"

void control_c(void)
{
	my_putchar('\n');
	display_cursor();
}

void pid_management(param_t *param, int pid)
{
	if (param->pid == 0) {
		pid = 0;

		while (param->env[pid]) {
			param->strcat = my_strcat(param->env[pid], param->arg[0]);
			command_basics(param);
			pid++;
		}

		if (param->env[pid] == 0 && !str_equals(param->buff, "cd")) {
			my_putstr("Error: Unknown command. Type help to see the");
			my_putstr(" commands list.\n");
		}

		exit(0);
	} else {
		wait(&param->status);
	}
}