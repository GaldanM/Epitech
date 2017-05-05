##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Sun Mar  2 19:12:27 2014 moulin_c
##

NAME	=	sudoki-bi

SRC	=	Lib/flags_1.c \
		Lib/flags_2.c \
		Lib/flags_3.c \
		Lib/foncs.c \
		Lib/my_getnbr.c \
		Lib/my_printf.c \
		Lib/my_putnbrbase.c \
		Lib/my_put_nbr.c \
		Lib/my_putstr_rev.c \
		Lib/my_strcat.c \
		Lib/my_strcmp.c \
		Lib/my_strcpy.c \
		Lib/my_strlen.c \
		Lib/my_strncat.c \
		Lib/my_strncmp.c \
		Lib/tab_point.c \
		display.c \
		foncs_sudo.c \
		get_next_line.c \
		my_putstr.c \
		parser.c \
		resolve.c \
		tests.c \
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
