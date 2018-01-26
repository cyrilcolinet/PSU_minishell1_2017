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
	unsigned int i = 0;

	if (ptr == NULL || !size)
		return (NULL);

	while (i < size + 1)
		*(ptr + i++) = 0;

	return (ptr);
}