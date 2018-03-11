/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** prompt_manager functions
*/

# include "minishell.h"

char *parse_cwd(char *buffer)
{
	char *dup = my_strdup(buffer);

	if (my_str)
}

void display_prompt(void)
{
	char buffer[4097];
	char *cwd = getcwd(buffer, 4096);
	char *pcwd = parse_cwd(cwd);
}
