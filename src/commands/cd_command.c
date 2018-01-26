/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** cd_command functions
*/

# include "my.h"
# include "minishell.h"

void change_directory(char *path)
{
	char buff[4097];
	char *cwd = getcwd(buff, 4096);
	char *ret;

	if (chdir(path)) {
		my_putstr("Error: ");

		if (access(path, F_OK) == -1)
			ret = "No such file or directory. (";
		else if (access(path, R_OK) == -1)
			ret = "Permission denied. (";
		else
			ret = "Not a directory. (";

		my_putstr(ret);
		my_putstr(path);
		my_putstr(")\n");
	} else {
		// setenv OLDPWD => cwd
	}
}

int check_cd_args(char **command)
{
	return (0);
}

int cd_command(char **command, param_t *param)
{
	char *home_path = env_get_var("HOME", param->env);

	if (command[1] == NULL) {
		change_directory(home_path);
		return (1);
	}

	if (check_cd_args(command))
		return (1);

	return (1);
}