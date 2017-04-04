##
## Makefile for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Nov 10 18:06:09 2013 moulin_c
## Last update Sun Nov 10 18:17:22 2013 moulin_c
##

SRC=	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	arrangement.c \
	checks.c \
	eval_expr.c \
	if_carry.c \
	my_add.c \
	my_combl.c \
	my_subs.c \
	strlen_mod.c \
	main.c

OBJ=	$(SRC:.c=.o)

NAME=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	@cc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
