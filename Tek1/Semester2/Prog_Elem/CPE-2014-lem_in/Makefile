##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Sat Apr 26 17:59:46 2014 moulin_c
##

NAME		=	lem-in

SRC_GRAPH	=	Graph/add_elem.c \
			Graph/fill_function.c \
			Graph/fill_list.c \
			Graph/fill_pipes.c \
			Graph/my_put_in_list_end.c \
			Graph/my_recup_elem.c \
			Graph/my_show_list.c \
			Graph/make_tab.c

SRCS		=	$(SRC_GRAPH)

INC		=	-I Includes

OBJ		=	$(SRCS:.c=.o)

LIB		=	-L Lib/ -lmy

CFLAGS		+=	$(INC)#-W -Wall -Wextra

all:			$(NAME)

$(NAME):		$(OBJ)
			gcc -o $(NAME) $(OBJ) $(LIB)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
