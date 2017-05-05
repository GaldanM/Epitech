# COMPIL

CC		=	g++

RM		=	rm -f

# NAMES

NAME		=	trade

# FOLDERS

FOLD_SRCS	=	Sources/

## FLAGS

CPPFLAGS	+=	-W -Wall -Werror -Wextra -I ./Includes

## SOURCES

SRCS		=	$(FOLD_SRCS)Trader.cpp \
			$(FOLD_SRCS)main.cpp

## OBJS

OBJS		=	$(SRCS:.cpp=.o)

# RULES

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
