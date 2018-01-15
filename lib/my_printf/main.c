/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** main function
*/

# include "my_printf.h"

int main(void)
{
	my_printf("%s%c%s\n", "coucou", ' ', "toi");
	my_printf("Je suis un string sans rien dedans\n");
	my_printf("J'ai actuellement %d%% de %s%c\n", 68, "batteri", 'e');
	my_printf("%d + %d = %d\n", 4, 6, (4 + 6));
	my_printf("%S\n", "Cou\006ou");

	return (0);
}