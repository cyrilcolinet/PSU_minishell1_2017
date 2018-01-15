##
## EPITECH PROJECT, 2017
## libmy_printf
## File description:
## Makefile libmy_printf
##

.PHONY				: all, clean, fclean, re

NAME 				= libmy_printf.a

SRC 				= my_printf.c 			\
					  flags_hexadecimal.c 	\
					  flags_number.c 		\
					  flags_string.c 		\
					  flags_unsigned.c 		\
					  functions.c 			\
					  my_put_nbr_base.c 	\
					  utils.c 				

CFLAGS 				= -Wall -Wextra -I./include

CC					= gcc

AR 					= ar rc

CP 					= cp

RM 					= rm -f

INCLUDE 			= ./include

REMOTE_INCLUDE 		= ../../include/

INCLUDE_FILE		= my_printf.h

OBJ 				= $(SRC:.c=.o)

all:				$(NAME)
					$(CP) $(NAME) ../$(NAME)
					$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)

$(NAME):			$(OBJ)
					$(AR) $(NAME) $(OBJ)

clean:
					$(RM) $(OBJ)

fclean: 			clean
					$(RM) ../$(NAME)
					$(RM) $(NAME)
					$(RM) $(REMOTE_INCLUDE)$(INCLUDE_FILE)

re: 				fclean all