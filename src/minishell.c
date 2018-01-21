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
		param->pid = fork();

		if (param->pid == -1)
			exit(0);

		param->fdesc = read(0, param->buff, 4067);
	}
}

int minishell(char **env)
{
	param_t *param = my_malloc(sizeof(*param));

	signal(SIGINT, control_c);
	param->env = copy_env(env);
	param->env_copy = env;

	if (param->env == NULL)
		my_puterr("Error during copy of PATH variable.\n", true);

	my_putstr("$> ");
	start_shell(param);

	free(param->env);
	free(param);
	return (0);
}