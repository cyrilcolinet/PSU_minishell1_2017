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
	
}