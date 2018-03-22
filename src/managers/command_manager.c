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
	int ret = 0;
	int wait_ret = -1;
	char **env = NULL;

	printf("fork = %d, %s\n", pid, bin_path);
	signal(SIGINT, proc_signal_handler);
	if (pid == 0) {
		if ((env = convert_list_to_array(shell->env)) != NULL)
			execve(bin_path, arg, env);
		my_freetab(env);
	} else if (pid < 0) {
		free(bin_path);
		my_putstr("Fork failed to create new process.\n");
		return (false);
	}
	wait_ret = waitpid(pid, &ret, 0);
	if (WTERMSIG(ret) != 0 && WTERMSIG(ret) != SIGINT) {
		my_putstr(strsignal(WTERMSIG(ret)));
		my_putstr("\n");
	}
	kill(wait_ret, SIGKILL);
	if (bin_path)
		free(bin_path);
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
	stat_t info;

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

	if (lstat(arg[0], &info) != -1) {
		if (info.st_mode & S_IXUSR) {
			run_command(my_strdup(arg[0]), arg, shell);
			my_freetab(arg);
			return (1);
		}
	}
	my_putstr(arg[0]);
	my_putstr(" : Command not found.\n");
	my_freetab(arg);
	return (res);
}
