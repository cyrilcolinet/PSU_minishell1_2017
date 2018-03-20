/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** enviroment_actions functions
*/

# include "minishell.h"

void env_del_variable(char *var, shell_t *shell)
{
	env_t *tmp = shell->env;

	while (tmp->next != NULL) {
		if (my_strequ(tmp->next->variable, var)) {
			free(tmp->next->variable);
			free(tmp->next->content);
			tmp->next = tmp->next->next;
			free(tmp);
			return;
		}
		tmp = tmp->next;
	}
}

void env_set_variable(char *variable, char *content, shell_t *shell)
{
	env_t *tmp = shell->env;
	char *tmp_cont = NULL;
	char *v = NULL;
	char *c = NULL;

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

	v = my_strdup(variable);
	c = my_strdup(content);
	tmp->next = new_environment_entry(v, c, tmp->next);
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
