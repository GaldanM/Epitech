##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Sun Jan 19 18:02:47 2014 moulin_c
##

NAME	=	my_select

SRC	=	add_elem_circ_end.c \
		disp_select.c \
		do_caps.c \
		gere_key.c \
		make_list_circ.c \
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(SRC) -lncurses -lmy -L ../../../../Lib/Piscine-C-lib/ -g

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
