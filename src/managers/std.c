/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** std manager functions
*/

# include "my.h"
# include "minishell.h"

void display_shell(void)
{
	my_putstr("$> ");
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