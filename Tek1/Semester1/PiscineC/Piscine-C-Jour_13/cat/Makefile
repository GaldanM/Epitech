##
## Makefile for cat in /home/moulin_c/rendu/Piscine-C-Jour_13/cat
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Thu Oct 24 18:02:37 2013 moulin_c
## Last update Thu Oct 24 18:57:10 2013 moulin_c
##

NAME =  cat

OBJ =   $(SRC:.c=.o)

SRC =	my_putstr_mod.c \
	checks.c \
	main.c \
	cat.c

all:    $(NAME)

$(NAME):	$(OBJ)
	@cc -o $(NAME) $(OBJ) -lmy -L../../Piscine-C-lib/

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm $(NAME)

re:     fclean all
