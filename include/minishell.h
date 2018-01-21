/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell functions (header file)
*/

# ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

typedef struct params {
		char 	**env;
		char 	**env_copy;
		char 	**arg;
		char	buff[4067];
		pid_t 	pid;
		int 	fdesc;
		char 	*strcat;
		int 	status;
} param_t;

int 	minishell(char **env);

void 	control_c(void);
void 	control_exit(char *buff);

bool 	str_equals(char *src, char *find);
char 	**copy_env(char **env);

# endif