/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** structs header file
*/

# ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

struct 	env_t;

typedef struct env_t {
	char 			*variable;
	char 			*content;
	struct env_t 	*next;
} 	env_t;

typedef struct shell_t {
	int 			status;
	char 			*path;
	env_t 			*env;
} 	shell_t;

# endif
