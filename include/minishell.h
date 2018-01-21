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
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct stat stat_t;

typedef struct params {
		char 	**env;
		int 	env_size;
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

void 	command_exit(char *buffer);
void 	command_basics(param_t *param);

void 	correct_exit(param_t *param);
bool 	str_equals(char *src, char *find);
char 	**copy_env(char **env, param_t *param);
param_t *init_strcut(void);
void 	display_cursor(void);

# endif