/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** cd_command functions
*/

# include "minishell.h"

void change_dir(char *path, shell_t *shell)
{
	char buffer[4097];
	char *cwd = getcwd(buffer, 4096);

	if (!chdir(path)) {
		env_set_variable("OLDPWD", cwd, shell);
	} else {
		my_putstr("error");
	}
}

int cd_command(char *stdin, char **arg, shell_t *shell)
{
	char *home = env_get_variable("HOME", shell);

	if (arg[1] == NULL) {
		change_dir(home, shell);
		return (0);
	}
	return (0);
}
