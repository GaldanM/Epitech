##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Thu Mar 20 12:16:25 2014 moulin_c
##

NAME_1	=	Client/client

SRC_1	=	Srcs/client.c \
		Srcs/my_get_nbr_base.c \
		Srcs/foncs_talk.c \
		Client/main.c

OBJ_1	=	$(SRC_1:.c=.o)

NAME_2	=	Server/server

SRC_2	=	Srcs/server.c \
		Srcs/foncs_talk.c \
		Srcs/my_put_nbr.c \
		Server/main.c

OBJ_2	=	$(SRC_2:.c=.o)

CFLAGS	=	-W -Wall -Wextra

all:		$(NAME_1) $(NAME_2)

$(NAME_1):	$(OBJ_1)
		gcc -o $(NAME_1) $(SRC_1) $(CFLAGS)

$(NAME_2):	$(OBJ_2)
		gcc -o $(NAME_2) $(SRC_2) $(CFLAGS)

clean:
		rm -f $(OBJ_1)
		rm -f $(OBJ_2)

fclean:		clean
		rm -f $(NAME_1)
		rm -f $(NAME_2)

re:		fclean all

.PHONY:		all clean fclean re
