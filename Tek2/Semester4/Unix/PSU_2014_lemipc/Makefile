##
## Makefile for Makefile in /home/ounajj_k/rendu/PSU_2014_lemipc
## 
## Made by Khaled Ounajjar
## Login   <ounajj_k@epitech.net>
## 
## Started on  Sun Mar  8 23:12:02 2015 Khaled Ounajjar
## Last update Sun Mar  8 23:16:17 2015 Khaled Ounajjar
##

CC	=	gcc

RM 	=	rm -f 

CFLAGS	+=	-W -Wall -Werror -Werror

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	lemipc

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
