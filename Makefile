##
## EPITECH PROJECT, 2017
## minishell
## File description:
## Makefile with build project rule and units tests
##

.PHONY			: all, fclean, clean, re, tests_run, lib

NAME 			= mysh

UT_NAME 		= units

SRC 			= src/main.c 					\
				  src/minishell.c 				\
				  src/utils.c 					\
				  src/controls.c

UT_SRC 			= src/main.c 					\
				  src/minishell.c 				\
				  tests/minishell_tests.c

CFLAGS 			= -Wall -Wextra -I./include -L./lib -lmy --coverage

UT_CFLAGS 		= -lcriterion -lgcov --coverage

EXTRA_FLAGS 	= -g3

CC 				= gcc

RM 				= rm -f

OBJ 			= $(SRC:.c=.o)

UT_OBJ			= $(UT_SRC:.c=.o)

all: 			lib $(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) -o $(NAME)

lib:
				make -C ./lib

clean:
				$(RM) $(OBJ)
				$(RM) $(UT_OBJ)
				$(RM) vgcore.*
				$(RM) src/*.gc*
				$(RM) tests/*.gc*

fclean: 		clean
				$(RM) $(NAME)
				$(RM) $(UT_NAME)
				make fclean -C ./lib

re: 			fclean all

tests_run:		fclean $(UT_OBJ)
				$(CC) $(CFLAGS) $(UT_CFLAGS) $(UT_OBJ) -o $(UT_NAME)
				./$(UT_NAME)