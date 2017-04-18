CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra -Werror -Wall -std=gnu99

NAME	=	menger

SRCS	=	menger.c \
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
