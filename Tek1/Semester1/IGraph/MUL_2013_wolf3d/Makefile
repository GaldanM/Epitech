##
## Makefile for EVent in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/Event_square
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Tue Dec 31 15:40:41 2013 moulin_c
## Last update Sun Jan 12 01:59:00 2014 moulin_c
##

NAME	=	wolf3d

SRC	=	draw_line.c \
		foncs_mlx.c \
		display_wolf.c \
		transf.c \
		get_tab_int.c \
		calculs_wolf.c \
		my_putstr.c \
		get_next_line.c \
		main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) -L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11 -g -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
