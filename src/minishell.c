/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell functions
*/

# include "my.h"
# include "minishell.h"

void start_shell(param_t *param)
{
	int pid;

	param->fdesc = read(0, param->buff, 4067);

	while (param->fdesc > 0) {
		param->arg = my_strtok(param->buff, " ");

		command_exit(param->buff);

		param->pid = fork();

		if (param->pid == -1)
			exit(0);

		param->fdesc = read(0, param->buff, 4067);
	}
}

int minishell(char **env)
{
	param_t *param = init_struct();

	signal(SIGINT, control_c);
	param->env = copy_env(env, param);
	param->env_copy = env;

	if (param->env == NULL)
		my_puterr("Error during copy of PATH variable.\n", true);

	display_cursor();
	start_shell(param);
	correct_exit(param);

	return (0);
}