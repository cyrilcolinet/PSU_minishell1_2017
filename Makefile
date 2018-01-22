##
## EPITECH PROJECT, 2017
## minishell
## File description:
## Makefile with build project rule and units tests
##

## Color variables

SUCCESS			= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

## Compilation variables

.PHONY			: all, fclean, clean, re, tests_run, lib

NAME 			= mysh

UT_NAME 		= units

SRC 			= src/main.c 					\
				  src/minishell.c 				\
				  src/utils.c 					\
				  src/controls.c 				\
				  src/commands.c

UT_SRC 			= src/main.c 					\
				  src/minishell.c 				\
				  tests/minishell_tests.c

CFLAGS 			= -Wall -Wextra -I./include --coverage

UT_CFLAGS 		= -lcriterion -lgcov --coverage

EXTRA_FLAGS		= -L./lib/ -lmy

CC 				= gcc

RM 				= rm -f

OBJ 			= $(SRC:.c=.o)

LIB_OBJ			= ./lib/my/*.o

UT_OBJ			= $(UT_SRC:.c=.o)

all: 			lib $(NAME)
				@$(call SUCCESS, "Project successfully compiled.")

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)
				@$(call SUCCESS, "All objects files successfully regrouped in ./$(NAME) binary file.")

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
				@$(call SUCCESS, "Project fully cleaned.")
				make fclean -C ./lib

re: 			fclean all

tests_run:		fclean $(UT_OBJ)
				$(CC) $(CFLAGS) $(UT_CFLAGS) $(UT_OBJ) -o $(UT_NAME)
				@$(call SUCCESS, "Unitary tests successfully compiled. Start it !")
				./$(UT_NAME)
