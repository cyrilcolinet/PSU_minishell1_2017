/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** utilities functions
*/

# include "my.h"
# include "minishell.h"

pCom *configure_commands(pCom **arr)
{
	*arr = (pCom*)malloc(sizeof(pCom) * 6);

	if (*arr == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		return (NULL);
	}

	(*arr)[0] = exit_command;
	(*arr)[1] = exit_command;
	(*arr)[2] = exit_command;
	(*arr)[3] = exit_command;
	(*arr)[4] = exit_command;
	(*arr)[5] = exit_command;

	return (*arr);
}

void configure_pointer_com(param_t *param)
{
	pCom *func = configure_commands(&func);
	int key = 0;

	while (param->builtin[key]) {
		param->com->command = my_strdup(param->builtin[key]);
		param->com->fct = *func;
		key++;
		func++;
		param->com++;
	}
}

param_t *configure_params(void)
{
	param_t *param = malloc(sizeof(*param));

	if (param == NULL) {
		write(2, "Malloc failed. Aborded.\n", 24);
		return (NULL);
	}

	param->env = NULL;
	param->com = malloc(sizeof(com_t) * 6);
	param->builtin = malloc(sizeof(char *) * 6);

	if (param->com == NULL || param->builtin)
		return (NULL);

	configure_pointer_com(param);

	return (param);
}

void display_shell(void)
{
	my_putstr("$> ");
}

void redirect_stdin(char **stdin)
{

}