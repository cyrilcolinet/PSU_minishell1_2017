##
## EPITECH PROJECT, 2017
## my_sokoban
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, library

NAME 			= mysh

SRC 			= src/main.c 				\
				  src/minishell.c

CFLAGS 			= -Wall -Wextra -I./include

EXTRA_FLAGS 	= -L./lib/ -lmy -lgnl

CC 				= gcc

RM 				= rm -f

OBJ 			= $(SRC:.c=.o)

all: 			library $(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) ./lib/my/*.o -o $(NAME)

library:
				make -C ./lib

clean:
				$(RM) $(OBJ)
				$(RM) vgcore.*

fclean: 		clean
				$(RM) $(NAME)
				make fclean -C ./lib

re: 			fclean all

tests_run:		re
				@echo "Running units tests..."

