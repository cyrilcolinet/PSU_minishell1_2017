/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** check_binaries functions
*/

# include "minishell.h"

bool check_binaries(char **arg, shell_t *shell)
{
	int i = 0;
	char **path = my_strtok(shell->path, ':');
	char *bin_path = NULL;
	stat_t info;

	while (path && path[i]) {
		if (my_strstartswith(arg[0], path[i])) {
			bin_path = my_strdup(arg[0]);
		} else {
			bin_path = path_join(path[i], arg[0]);
		}
		if (lstat(bin_path, &info) < 0) {
			free(bin_path);
		} else {
			my_freetab(path);
			return (false);
		}
	}
	my_freetab(path);
	return (false);
}
