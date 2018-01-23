/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** signal_handler functions
*/

# include "my.h"
# include "minishell.h"

void signal_handler(int sig)
{
	if (sig == SIGINT) {
		my_putstr("\n");
		display_shell();
		signal(SIGINT, signal_handler);
	}
}