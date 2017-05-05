# COMPIL

CC		=	g++

RM		=	rm -f

# NAMES

NAME		=	autoCompletion

# FOLDERS

FOLD_SRCS	=	Sources/

FOLD_INCS	=	Includes/

## FLAGS

CPPFLAGS	+=	-W -Wall -Werror -Wextra -I $(FOLD_INCS) -std=c++11

## SOURCES

SRCS		=	$(FOLD_SRCS)Address.cpp \
			$(FOLD_SRCS)Dictionnary.cpp \
			$(FOLD_SRCS)main.cpp \
			$(FOLD_SRCS)MyError.cpp

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
