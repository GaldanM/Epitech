##
## Makefile for printf in /home/moulin_c/rendu/tests/printf
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sat Nov 16 18:00:19 2013 moulin_c
## Last update Sat Nov 16 18:28:07 2013 moulin_c
##

NAME =		libmy.a

OBJ =		$(SRC:.c=.o)

SRC =		flags_1.c \
		flags_2.c \
		flags_3.c \
		foncs.c \
		my_putnbrbase.c \
		my_put_nbr.c \
		tab_point.c \
		printf.c

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re :		fclean all

.PHONY:		all clean fclean re
