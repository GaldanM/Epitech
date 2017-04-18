CC	=	g++

RM	=	rm -f

CFLAGS	+=	-W -Wall -Werror

CFLAGS	+=	-ansi -pedantic

CFLAGS	+=	-I.

NAME	=	my_cat

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
