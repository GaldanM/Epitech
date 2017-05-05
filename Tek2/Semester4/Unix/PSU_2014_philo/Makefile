CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror

THREAD	=	-lpthread

NAME	=	philo

SRCS	=	fonc_philo.c \
		init_philo.c \
		main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(THREAD)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
