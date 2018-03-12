/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** env_manager functions
*/

# include "minishell.h"

env_t *new_environment_entry(char *var, char *content, env_t *env)
{
	env = malloc(sizeof(env_t));

	if (env == NULL || var == NULL || content == NULL)
		return (NULL);

	env->variable = var;
	env->content = content;
	env->next = NULL;
	return (env);
}

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

void fill_environment(env_t *env_s, char **env)
{
	env_t *tmp = env_s;
	char **arr = NULL;
	char *var = NULL;
	char *content = NULL;

	while (*env != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;

		arr = my_strtok(*env, '=');
		var = my_strdup(arr[0]);
		content = join_next_values(arr);
		tmp->next = new_environment_entry(var, content, tmp->next);
		my_freetab(arr);

		if (tmp->next == NULL)
			return;

		env++;
	}
}
