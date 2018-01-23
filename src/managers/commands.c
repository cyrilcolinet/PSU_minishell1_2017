/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** commands manager functions
*/

# include "my.h"
# include "minishell.h"

int check_binaries(char **command)
{
	(void)command;
	return (0);
}

int check_command(char **command)
{
	(void)command;
	return (0);
}

int run_command(char *path, char **args, param_t *param)
{
	pid_t pid = fork();

	signal(SIGINT, proc_signal_handler);

	if (pid == 0) {
		execve(path, args, param->env);
	} else if (pid < 0) {
		free(path);
		write(2, "Fork failed to create a new process.\n", 38);
		return (-1);
	}

	wait(&pid);

	if (path != NULL)
		free(path);

	return (1);
}

int exec_command(char **command, param_t *param)
{
	stat_t info;
	int own = check_command(command);
	command = my_strtok(command[0], " ");

	if (own == 1 || check_binaries(command))
		return (0);
	else if (own < 0)
		return (-1);

	if (lstat(command[0], &info) != -1) {
		if (info.st_mode & S_IFDIR) {
			//change_dir(command[0], 0);
			return (0);
		} else if (info.st_mode & S_IXUSR) {
			return (run_command(my_strdup(command[0]), command, param));
		}
	}

	my_printf("Error: unknown command '%s'.\n", command[0]);

	return (0);
}