CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall

CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-I.

NAME	=	elcrypt

SRCS	=	encrypt.c	\
		foncs_crypt.c	\
		foncs_param.c	\
		get_keys.c	\
		param.c		\
		main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
