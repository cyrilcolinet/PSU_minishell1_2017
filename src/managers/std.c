/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** std manager functions
*/

# include "my.h"
# include "minishell.h"

char *parse_shell_pwd(char *path, int reverse)
{
	char *home = "/home/cyrilcolinet/";
	char *new;
	(void)reverse;

	if (path == NULL)
		return (NULL);

	return (path);
}

void display_shell(void)
{
	char buff[4097];
	char *cwd = getcwd(buff, 4096);
	char *pcwd = parse_shell_pwd(cwd, 0);

	my_putstr(pcwd);
	//free(pcwd);
	my_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");
	my_putstr("\033[0m\033[34m═\033[0m\033[35m—\033[0m$ ");
}

char *str_configure(unsigned int size)
{
	char *ptr = malloc(sizeof(char) * (size + 1));

	if (ptr == NULL)
		return (NULL);

	*ptr = 0;

	return (ptr);
}

void redirect_stdin(char **stdin, param_t *param)
{
	int ret, count = 1, i = 0;
	char buffer;

	*stdin = str_configure(1);

	while ((ret = read(0, &buffer, 1)) && buffer != '\n') {
		*(*stdin + i++) = buffer;
		*stdin = my_realloc(*stdin, count + 1);
		count++;
	}

	*(*stdin + i) = 0;

	if (ret == 0) {
		free(*stdin);
		exit_minishell(param);
	}

	// parse input
}