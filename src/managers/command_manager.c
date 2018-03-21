/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** command_manager functions
*/

# include "minishell.h"

bool run_command(char *bin_path, char **arg, shell_t *shell)
{
	pid_t pid = fork();
	char **env = convert_list_to_array(shell->env);

	signal(SIGINT, SIG_IGN); // TODO: à faire
	if (pid == 0) {
		if (env)
			execve(bin_path, arg, env);
	} else if (pid < 0) {
		free(bin_path);
		my_putstr("Fork failed to create new process.\n");
		my_freetab(env);
		return (false);
	}
	wait(&pid);
	if (bin_path)
		free(bin_path);
	my_freetab(env);
	return (true);
}

int builtin(char *stdin, char **arg, shell_t *shell)
{
	int res = 0;

	if (my_strequ(arg[0], "exit"))
		res = exit_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "cd"))
		res = cd_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "env"))
		print_environment(shell);
	else if (my_strequ(arg[0], "setenv"))
		res = setenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "unsetenv"))
		res = unsetenv_command(stdin, arg, shell);
	else if (my_strequ(arg[0], "printenv"))
		res = printenv_command(stdin, arg, shell);

	return (res);
}

int command_executor(char *stdin, shell_t *shell)
{
	int res = 1;
	char **arg = my_strtok(stdin, ' ');

	if (arg[0] == NULL) {
		my_freetab(arg);
		return (1);
	}

	if ((res = builtin(stdin, arg, shell)) == 1 || bins(arg, shell)) {
		my_freetab(arg);
		return (res);
	} else if (res < 0) {
		my_freetab(arg);
		return (-1);
	}

	my_putstr(arg[0]);
	my_putstr(" : Command not found.\n");
	my_freetab(arg);
	return (res);
}
