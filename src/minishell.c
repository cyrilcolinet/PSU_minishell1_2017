/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Minishell functions
*/

# include "minishell.h"

void exit_minishell(param_t *param)
{
	int loop = 0;
	int envlen = env_length(param->env);

	if (param->env != NULL) {
		while (loop < envlen) {
			free(param->env[loop]);
			loop++;
		}

		loop = 0;
		free(param->env);
	}

	while (loop < 6) {
		free(param->com->command);
		param->com++;
		loop++;
	}

	free(param->builtin);
	free(param->com);
	free(param);
	exit(0);
}

int minishell(int ac, char **av, char **env)
{
	param_t *param = configure_params();
	char *stdin = NULL;
	int result;

	if (param == NULL)
		return (84);

	env_configure(env, param);

	while (true) {
		display_shell();
		signal(SIGINT, signal_handler);
		redirect_stdin(&stdin);

		if ((result = exec_command(stdin)) == -1)
			break;
	}

	exit_minishell(param);
	return (0);
}