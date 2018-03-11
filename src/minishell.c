/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions
*/

# include "minishell.h"

int main_minishell(int ac, char **av, char **env)
{
	shell_t *shell = configure(env);
	int status = 0;
	(void)ac, (void)av;

	if (shell == NULL)
		return (84);

	printf("%s\n", env_get_variable("PATH", shell));
	env_set_variable("PATH", "fraise", shell);
	printf("%s\n", env_get_variable("PATH", shell));

	status = shell->status;
	free_all(shell);
	return (status);
}
