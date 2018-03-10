/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions (header file)
*/

# ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "my.h"
# include "structs.h"

// minishell.c
int 		main_minishell(int ac, char **av, char **env);

// utils/struct_utils.c
void 		free_all(shell_t *shell);
env_t 		*configure_env(char **env);
shell_t 	*configure(char **env);

// utils/parsing_utils.c
char 		*realloc_char(char *ptr, unsigned int size);
char 		*join_next_values(char **array);

// managers/env_manager.c
void 		fill_environment(env_t *env_s, char **env);

# endif
