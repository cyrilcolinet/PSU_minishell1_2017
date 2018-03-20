/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions
*/

# include "minishell.h"

void minishell(shell_t *shell)
{
	char *stdin = NULL;
	int result = 0;

	while (result != -1) {
		signal(SIGINT, SIG_IGN);
		display_prompt(shell);
		redirect_stdin(&stdin);
		result = command_executor(stdin, shell);
		free(stdin);
	}
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
