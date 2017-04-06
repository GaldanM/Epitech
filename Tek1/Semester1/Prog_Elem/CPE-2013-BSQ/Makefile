##
## Makefile for bsq in /home/moulin_c/rendu/Modules/C_Prog_Elem/BSQ/CPE-2013-BSQ
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Dec  8 11:11:10 2013 moulin_c
## Last update Sun Dec  8 18:23:39 2013 moulin_c
##

NAME	=	bsq

SRCS	=	get_next_line.c \
		my_show_wordtab.c \
		foncs.c \
		more_square.c \
		my_getnbr.c \
		checks.c \
		main.c

OBJ	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
