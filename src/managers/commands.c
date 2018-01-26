/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** commands manager functions
*/

# include "my.h"
# include "minishell.h"

int executable(char *bin, stat_t info, char **c, param_t *p)
{
	if (info.st_mode & S_IXUSR) {
		if (info.st_mode & S_IXUSR) {
			return (run_command(bin, c, p));
		} else {
			my_printf("Error: permission denied for '%s'.\n", bin);
		}

		free(bin);
		return (1);
	}

	free(bin);
	return (0);
}

int check_binaries(char **command, param_t *param)
{
	int i = 0;
	char *bin_path;
	stat_t info;

	while (param->path && param->path[i]) {
		if (my_strstartswith(command[0], param->path[i]))
			bin_path = my_strdup(command[0]);
		else
			bin_path = my_pathjoin(param->path[i], command[0]);

		if (lstat(bin_path, &info) == -1) {
			free(bin_path);
		} else {
			return (executable(bin_path, info, command, param));
		}
		i++;
	}

	return (0);
}

int check_command(char **command, param_t *param)
{
	int ret = 0;

	if (my_strcmp(command[0], "exit") == 0) {
		ret = exit_command(command, param);
	} else if (my_strcmp(command[0], "env") == 0) {
		ret = env_command(command, param);
	} else if (my_strcmp(command[0], "setenv") == 0) {
		ret = setenv_command(command, param);
	} else if (my_strcmp(command[0], "cd") == 0) {
		ret = cd_command(command, param);
	}

	if (ret != 0)
		my_freetab(command);

	return (ret);
}

int run_command(char *path, char **args, param_t *param)
{
	pid_t pid = fork();

	signal(SIGINT, proc_signal_handler);

	if (pid == 0) {
		execve(path, args, param->env);
	} else if (pid < 0) {
		free(path);
		my_freetab(args);
		write(2, "Fork failed to create a new process.\n", 38);
		return (-1);
	}

	wait(&pid);

	if (path != NULL)
		free(path);

	my_freetab(args);
	my_putstr("\n");

	return (1);
}

int exec_command(char **command, param_t *param)
{
	stat_t info;
	int own = check_command(command, param);

	if (own == 1 /*|| check_binaries(command, param)*/)
		return (0);
	if (own < 0)
		return (-1);

	if (lstat(command[0], &info) != -1) {
		if (info.st_mode & S_IFDIR) {
			//change_dir(command[0], 0);
			my_freetab(command);
			return (0);
		} else if (info.st_mode & S_IXUSR) {
			return (run_command(my_strdup(command[0]), command, param));
		}
	}

	my_putstr("Error: unknown command '");
	my_putstr(command[0]);
	my_putstr("'.\n");
	my_freetab(command);
	return (0);
}