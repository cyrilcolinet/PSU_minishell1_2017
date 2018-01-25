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

typedef struct environment {
	struct env 	*prev;
	char 		*var;
	char 		*content;
	struct env  *next;
} env_t;

typedef struct parameters {
		char	**env;
		env_t 	*environment;
} 		param_t;

void 	exit_minishell(param_t *param);
int 	minishell(int ac, char **av, char **env);

int 	env_length(char **env);
void 	env_configure(char **env, param_t *param);
char 	*env_get_var(char *variable, char **env);

void 	proc_signal_handler(int signal);
void 	signal_handler(int signal);

void 	my_free_array(char **arr);
param_t *configure_params(void);

void 	display_shell(void);
void 	redirect_stdin(char **stdin, param_t *param);

int		check_libraries(char **command);
int 	check_command(char *command, param_t *param);
int 	run_command(char *path, char **args, param_t *param);
int 	exec_command(char **command, param_t *param);

int 	exit_command(char *stdin, param_t *param);
int 	env_command(char *stdin, param_t *param);


char *my_str_join(char *str1, char *str2);
char *my_str_joincl(char *str1, char *str2, int free_both);
bool my_str_endswith(char *str1, char *str2);
char *my_str_joinch(char *str, char delim);
char *my_pathjoin(char *str1, char *str2);
char *my_strchr(char *str, char delim);
bool my_str_startswith(char *str1, char *str2);

# endif