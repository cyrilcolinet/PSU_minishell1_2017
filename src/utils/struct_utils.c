/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** struct_utils functions
*/

# include "minishell.h"

env_t *configure_env(char **env)
{
	env_t *env_s = malloc(sizeof(env_t));

	if (env_s == NULL)
		return (NULL);

	return (env_s);
}

shell_t *configure(char **env)
{
	shell_t *shell = NULL;

	if (*env == NULL)
		return (NULL);

	shell = malloc(sizeof(shell_t));

	if (shell == NULL)
		return (NULL);

	shell->status = 0;
	shell->env = configure_env(env);

	if (shell->env == NULL)
		return (NULL);

	return (shell);
}
