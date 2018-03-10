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

# endif
