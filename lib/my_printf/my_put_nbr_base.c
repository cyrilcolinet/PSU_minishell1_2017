/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** my_put_nbr_base functions
*/

# include "my_printf.h"

int my_put_nbr_base(int nb, char *base)
{
	int res;
	int div = 1;
	int size_base = my_strlen(base);
	int out = 0;

	while ((nb / div) >= size_base)
		div *= size_base;

	while (div > 0) {
		res = (nb / div) % size_base;
		out += write(0, &base[res], 1);
		div /= size_base;
	}

	return (out);
}