/*
** EPITECH PROJECT, 2018
** my_library
** File description:
** my_str_configure function
*/

# include "my.h"

char *my_str_configure(unsigned int size)
{
	char *ptr = malloc(sizeof(char) * (size + 1));

	if (ptr == NULL)
		return (NULL);

	*ptr = 0;

	return (ptr);
}