##
## EPITECH PROJECT, 2017
## my_library
## File description:
## Makefile for lib
##

all:		libmy.a libmy_printf.a

libmy_printf.a:
			make -C ./my_printf

libmy.a:
			make -C ./my

clean:
			rm -f *.o

fclean:
			make fclean -C ./my
			make fclean -C ./my_printf

re:			fclean all
