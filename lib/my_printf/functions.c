/*
** EPITECH PROJECT, 2018
** libmy_printf
** File description:
** functions
*/

# include "my_printf.h"

int my_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int my_putstr(char *str)
{
	int output = 0;

	while (*str) {
		my_putchar(*str);
		output++;
		str++;
	}

	return (output);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

char *my_strcat(char *dest, char *src)
{
	int i = my_strlen(src);
	int j = 0;

	while (src[j]) {
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = 0;
	return (dest);
}

int my_put_nbr(int nb)
{
	int output = 0;

	if (nb == -2147483648) {
		output += my_putstr("-2147483648");
		return (output);
	}

	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
		output++;
	}

	if (nb > 9)
		output += my_put_nbr(nb / 10);

	output += my_putchar(nb % 10 + 48);
	return (output);
}