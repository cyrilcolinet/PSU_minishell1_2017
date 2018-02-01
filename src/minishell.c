/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** Minishell functions
*/

# include "my.h"
# include "minishell.h"

void exit_minishell(param_t *param)
{
	my_freetab(param->path);
	my_freetab(param->env);
	free(param);
	write(1, "\n", 1);
}

int minishell(int ac, char **av, char **env, int fd)
{
	param_t *param = configure_params(fd);
	char *stdin = NULL, *tmp;
	int result = 0, exit_sts;
	(void)ac, (void)av;

	if (param == NULL)
		return (84);

	env_configure(env, param);
	tmp = env_get_var("PATH", param->env);
	param->path = my_strtok(tmp, ':');

	while (result != -1) {
		display_shell();
		signal(SIGINT, signal_handler);
		redirect_stdin(&stdin, param);

		if (*stdin == 0) {
			free(stdin);
			continue;
		}

		result = exec_command(my_strtok(stdin, ' '), param);
		free(stdin);
	}

	exit_sts = param->exit_sts;
	exit_minishell(param);
	return (exit_sts);
}