##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Mon Jan  6 18:04:14 2014 moulin_c
##

NAME	=	push_swap

SRC	=	list_foncs.c \
		list_foncs2.c \
		list_foncs3.c \
		add_elem_circ_begin.c \
		add_elem_circ_end.c \
		del_elem_circ_begin.c \
		del_elem_circ_end.c \
		make_list_circ.c \
		my_show_list_circ.c \
		verif_sort.c \
		checks_push.c \
		my_getnbr.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putstr.c \
		my_swap.c \
		my_strcmp.c \
		my_strlen.c \
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@cc -o $(NAME) $(SRC)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
