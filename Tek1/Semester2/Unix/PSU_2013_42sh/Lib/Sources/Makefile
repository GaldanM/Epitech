##
## Makefile for Makefile in /home/moulin_c/rendu/Piscine-C-lib/my
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Mon Oct 21 10:02:08 2013 moulin_c
## Last update Sun May 25 07:48:44 2014 moulin_c
##

RM	=		rm -f

CFLAGS		+=	-Wall -Wextra -Werror -g

NAME	=		libmy.a

SRC	=		epur_str.c \
			get_next_line.c \
			my_putchar.c \
			my_putstr.c \
			my_strcat.c \
			my_strcmp.c \
			my_strcpy.c \
			my_strdup.c \
			my_strlen.c \
			my_strncmp.c \
			my_strncpy.c \
			write_to_fd.c

OBJ	=		$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@cp libmy.a ../
			@cp *.h ../../Includes/

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
