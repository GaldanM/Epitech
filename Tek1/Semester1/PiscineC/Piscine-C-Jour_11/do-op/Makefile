##
## Makefile for do_op in /home/moulin_c/rendu/Piscine-C-Jour_11/do-op
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Tue Oct 22 11:20:22 2013 moulin_c
## Last update Tue Oct 22 11:52:14 2013 moulin_c
##

SRC =	my_getnbr.c \
	operations.c \
	do-op.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c

NAME =	do-op

OBJ =	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)	
	cc -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	
	clean
	@rm $(NAME)

re:	
	fclean all
