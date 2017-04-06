##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Mon Feb 10 13:55:24 2014 moulin_c
##

NAME	=	allum1

SRC	=	do_caps.c \
		foncs_list.c \
		select_line.c \
		gere_key.c \
		gere_select.c \
		gere_enter.c \
		gere_err.c \
		game.c \
		computer.c \
		asks.c \
		display.c \
		read_key.c \
		my_getnbr.c \
		my_putstr.c \
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(SRC) -lncurses

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
