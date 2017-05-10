BCC		=	g++

RM		=	rm -f

FOLD_SRCS	=	src/

LIB		=	./LibGDL/libs

CXXFLAGS	+=	-I./LibGDL/includes/ -I./includes/

CXXFLAGS	+=	-W -Wall -Werror -Wextra

FLAGS		=	-L./LibGDL/libs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lstdc++ -lm

SRCS		=	$(FOLD_SRCS)ACharacter.cpp \
			$(FOLD_SRCS)AObject.cpp \
			$(FOLD_SRCS)AssetBomb.cpp \
			$(FOLD_SRCS)AssetRange.cpp \
			$(FOLD_SRCS)AssetSpeed.cpp \
			$(FOLD_SRCS)Bomb.cpp \
			$(FOLD_SRCS)Box.cpp \
			$(FOLD_SRCS)Fire.cpp \
			$(FOLD_SRCS)Floor.cpp \
			$(FOLD_SRCS)GameEngine.cpp \
			$(FOLD_SRCS)Ia.cpp \
			$(FOLD_SRCS)Img.cpp \
			$(FOLD_SRCS)main.cpp \
			$(FOLD_SRCS)Map.cpp \
			$(FOLD_SRCS)Master.cpp \
			$(FOLD_SRCS)Menu.cpp \
			$(FOLD_SRCS)MyError.cpp \
			$(FOLD_SRCS)Player1.cpp \
			$(FOLD_SRCS)Player2.cpp \
			$(FOLD_SRCS)Wall.cpp \

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	bomberman

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
