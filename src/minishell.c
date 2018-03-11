/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions
*/

# include "minishell.h"

void minishell(shell_t *shell)
{
	printf("%s\n", env_get_variable("PATH", shell));
	env_set_variable("PATH", "fraise", shell);
	printf("%s\n", env_get_variable("PATH", shell));
	env_set_variable("OUIOUIOUI", "Jesaispas", shell);
	printf("%s\n", env_get_variable("OUIOUIOUI", shell));
}

int main_minishell(int ac, char **av, char **env)
{
	shell_t *shell = configure(env);
	int status = 0;
	(void)ac, (void)av;

	if (shell == NULL)
		return (84);

	minishell(shell);
	status = shell->status;
	free_all(shell);
	return (status);
}
