##
## Makefile for FDF in /home/moulin_c/rendu/Modules/Igraph/MUL_2013_fdf
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Tue Nov 26 16:36:41 2013 moulin_c
## Last update Sat Dec  7 17:18:15 2013 moulin_c
##

NAME	=	fdf

SRCS	=	fdf.c \
		draw_line.c \
		proj_iso.c

OBJ	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@cc -o $(NAME) $(OBJ) -L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
