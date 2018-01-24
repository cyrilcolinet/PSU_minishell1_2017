/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Minishell functions
*/

# include "minishell.h"

void exit_minishell(param_t *param)
{
	my_free_array(param->env);
	free(param);
	write(1, "\n", 1);
	exit(0);
}

int minishell(int ac, char **av, char **env)
{
	param_t *param = configure_params();
	char *stdin = NULL;
	int result = 0;
	(void)ac, (void)av;

	if (param == NULL)
		return (84);

	env_configure(env, param);

	while (result != -1) {
		display_shell();
		signal(SIGINT, signal_handler);
		redirect_stdin(&stdin, param);

		if (*stdin == 0) {
			free(stdin);
			continue;
		}

		result = exec_command(&stdin, param);
		free(stdin);
	}

	exit_minishell(param);
	return (0);
}