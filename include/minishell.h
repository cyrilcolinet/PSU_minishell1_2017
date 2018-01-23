/*
** EPITECH PROJECT, 2018
** minishell
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

typedef struct stat stat_t;
typedef int (*pCom)(char *, char *);

typedef struct commands {
		char	*command;
		pCom 	fct;
}		com_t;

typedef struct parameters {
		char	**env;
		char 	**builtin;
		com_t	*com;
} 		param_t;

void 	exit_minishell(param_t *param);
int 	minishell(int ac, char **av, char **env);

int 	env_length(char **env);
void 	env_configure(char **env, param_t *param);

void 	signal_handler(int signal);

param_t *configure_params(void);

void 	display_shell(void);
void 	redirect_stdin(char **stdin, param_t *param);

int 	exit_command(char *stdin, char *command);

# endif