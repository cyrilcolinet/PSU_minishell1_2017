##
## EPITECH PROJECT, 2017
## minishell
## File description:
## Makefile with build project rule and units tests
##

## Color variables

SUCCESS			= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

## Compilation variables

NAME 			= mysh

SRCDIR 			= ./src/

SRCNAMES 		= main.c 					\
		  	  	  minishell.c 				\
		  	  	  utilities.c 				\
		  	  	  signal_handler.c 			\
		  	  	  managers/environment.c 	\
		  	  	  managers/commands.c 		\
		  	  	  managers/std.c 			\
		  	  	  commands/exit_command.c 	\
		  	  	  commands/env_command.c

SRC 			= $(addprefix $(SRCDIR), $(SRCNAMES))

INC 			= ./include

BUILDDIR 		= ./build/

BUILDSUBDIR 	= $(shell cd $(SRCDIR) && find . -mindepth 1 -type d -printf '%p\n')

BUILDOBJS 		= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

LIBDIR 			= ./lib/

LIBMY 			= ./lib/libmy.a

CC 				= gcc

CFLAGS 			= -Wall -Wextra -Werror -I$(INC)

DEBUG 			= -g3

## Rules

all: 			$(BUILDDIR) $(LIBMY) $(NAME)
				@$(call SUCCESS, "Project successfully compiled.")

$(BUILDDIR):
				mkdir -p $(BUILDDIR)
				$(foreach subdir, $(BUILDSUBDIR), mkdir -p build/$(subdir))

$(BUILDDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS) -c -o $@ $<
				@$(call SUCCESS, "Objct files created in $(BUILDDIR) folder")

$(NAME): 		$(BUILDOBJS)
				$(CC) $(CFLAGS) -L$(LIBDIR) -lmy -o $(NAME) $(BUILDOBJS) $(LIBDIR)/my/*.o $(LIBFT)
				@$(call SUCCESS, "All objects files successfully regrouped in ./$(NAME) binary file.")

$(LIBMY):
				make -C $(LIBDIR)

clean:
				rm -rf $(BUILDDIR)
				find -name '*.gc*' -delete -or -name 'vgcore.*' -delete
				make -C $(LIBDIR) clean
				@$(call SUCCESS, "Project fully cleaned.")

fclean: 		clean
				rm -rf $(NAME)
				make -C $(LIBDIR) fclean

re: 			fclean all

# Just in case those files exist in the root dir
.PHONY			: all fclean clean re