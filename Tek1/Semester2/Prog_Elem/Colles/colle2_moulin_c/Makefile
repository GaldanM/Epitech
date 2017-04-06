##
## Makefile for mastermind in /home/moulin_c/rendu/colle2_moulin_c
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Mon May  5 19:19:07 2014 moulin_c
## Last update Mon May  5 21:45:38 2014 moulin_c
##

NAME	=	bin/my_mastermind

SRC	=	src/args.c \
		src/displays.c \
		src/my_putnbr.c \
		src/func.c \
		src/mastermind.c \
		src/my_atoi.c \
		src/verif.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
