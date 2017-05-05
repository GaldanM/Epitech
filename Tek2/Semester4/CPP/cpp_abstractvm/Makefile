NAME		=	avm

CC		=	g++

RM		=	rm -f

CPPFLAGS	+=	-I ./inc

CPPFLAGS	+=	-W -Wall -Wextra -Werror

CPPFLAGS	+=	-std=c++11

FOLD_SRCS	=	srcs/

FOLD_PARSER	=	$(FOLD_SRCS)Parser/

FOLD_CLASSES	=	$(FOLD_SRCS)Classes/

SRCS_PARSER	=	$(FOLD_PARSER)Cmd.cpp		\
			$(FOLD_PARSER)MyError.cpp	\
			$(FOLD_PARSER)Parsers_foncs.cpp	\
			$(FOLD_PARSER)Parsers.cpp

SRCS_CLASSES	=	$(FOLD_CLASSES)Calculator.cpp	\
			$(FOLD_CLASSES)Op.cpp

SRCS		=	$(SRCS_PARSER)			\
			$(SRCS_CLASSES)			\
			$(FOLD_SRCS)main.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
