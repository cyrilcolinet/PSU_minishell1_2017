/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** env_manager functions
*/

# include "minishell.h"

void env_set_variable(char *variable, char *content, shell_t *shell)
{
	env_t *tmp = shell->env;
	char *tmp_cont = NULL;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->variable, variable)) {
			tmp_cont = my_strdup(content);
			tmp_cont = realloc_char(tmp_cont, my_strlen(content));
			free(tmp->next->content);
			tmp->next->content = my_strdup(tmp_cont);
			free(tmp_cont);
			return;
		}
		tmp = tmp->next;
	}
}

char *env_get_variable(char *variable, shell_t *shell)
{
	env_t *tmp = shell->env;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->variable, variable))
			return (tmp->next->content);
		tmp = tmp->next;
	}

	return (NULL);
}

void fill_environment(env_t *env_s, char **env)
{
	env_t *tmp = env_s;
	char **arr = NULL;

	while (*env != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = malloc(sizeof(env_t));

		if (tmp->next == NULL)
			return;

		arr = my_strtok(*env, '=');
		tmp->next->variable = my_strdup(arr[0]);
		tmp->next->content = join_next_values(arr);
		tmp->next->next = NULL;
		my_freetab(arr);
		env++;
	}
}
