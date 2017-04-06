##
## Makefile for Morse_encoder in /home/moulin_c/rendu/CPE_2013_Rush1
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sat Dec 14 02:09:21 2013 moulin_c
## Last update Sun Dec 15 21:14:46 2013 moulin_c
##

NAME	=	encodeur

SRCS	=	foncs_encod.c \
		encodeur.c

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
