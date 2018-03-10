/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** env_manager functions
*/

# include "minishell.h"

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
		printf("%s\n", *env);
		printf("%s=%s\n", tmp->next->variable, tmp->next->content);
		my_freetab(arr);
		env++;
	}
}
