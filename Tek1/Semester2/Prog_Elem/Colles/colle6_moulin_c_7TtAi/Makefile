##
## Makefile for boogle in /home/moulin_c/rendu/colle6_moulin_c_7TtAi
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Mon Jun  2 19:33:36 2014 moulin_c
## Last update Mon Jun  2 21:02:36 2014 moulin_c
##

NAME	=	my_boogle

CC	=	gcc

SRCS	=	srcs/create_map.c \
		srcs/my_boogle.c \
		srcs/funcs.c \
		srcs/main.c

OBJS	=	$(SRCS:.c=.o)

INC	=	includes/

CFLAGS	+=	-W -Wall -Wextra -Werror

CFLAGS	+=	-I $(INC)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
