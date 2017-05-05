##
## Makefile for make in /home/ounajj_k/rendu/cpp_nibbler
## 
## Made by Khaled Ounajjar
## Login   <ounajj_k@epitech.net>
## 
## Started on  Sun Apr  5 22:29:16 2015 Khaled Ounajjar
## Last update Sun Apr  5 22:38:18 2015 Khaled Ounajjar
##


CC		=	g++

CC_O		=	$(CC) -fPIC -c

CC_SO		=	$(CC) -shared -Wl,-soname,

RM		=	rm -f

NAME		=	nibbler

NAME_SFML	=	lib_nibbler_sfml.so

NAME_NCURSES	=	lib_nibbler_ncurses.so

NAME_XLIB       =       lib_nibbler_xlib.so

CPPFLAGS	+=	-W -Wall -Werror -Wextra

FLAGS		=	-rdynamic -ldl

SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

NCURSES_FLAGS	=	-lncurses

XLIB_FLAGS      =       -L/usr/X11R6/lib -lX11

SRCS		=	DLLoader.cpp \
			Game.cpp \
			main.cpp \
			MyError.cpp

SFML_SRCS	=	Lib_SFML.cpp

CURSES_SRCS	=	Lib_NCURSES.cpp

XLIB_SRCS       =       Lib_XLIB.cpp


OBJS		=	$(SRCS:.cpp=.o)

SFML_OBJS	=	$(SFML_SRCS:.cpp=.o)

CURSES_OBJS	=	$(CURSES_SRCS:.cpp=.o)

XLIB_OBJS       =       $(XLIB_SRCS:.cpp=.o)

all:			$(NAME_SFML) $(NAME_XLIB) $(NAME_NCURSES) $(NAME)


$(NAME_NCURSES):	$(CURSES_OBJS)
			$(CC_O) $(CURSES_SRCS) $(CPPFLAGS) -o $(CURSES_OBJS)
			$(CC_SO)$(NAME_NCURSES).1 -o $(NAME_NCURSES) $(CURSES_OBJS) $(NCURSES_FLAGS)

$(NAME_SFML):		$(SFML_OBJS)
			$(CC_O) $(SFML_SRCS) $(CPPFLAGS) -o $(SFML_OBJS)
			$(CC_SO)$(NAME_SFML).1 -o $(NAME_SFML) $(SFML_OBJS) $(SFML_FLAGS)

$(NAME_XLIB):		$(XLIB_OBJS)
			$(CC_O) $(XLIB_SRCS) $(CPPFLAGS) -o $(XLIB_OBJS)
			$(CC_SO)$(NAME_XLIB).1 -o $(NAME_XLIB) $(XLIB_OBJS) $(XLIB_FLAGS)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			$(RM) $(OBJS)
			$(RM) $(CURSES_OBJS)
			$(RM) $(SFML_OBJS)
			$(RM) $(XLIB_OBJS)

fclean:			clean
			$(RM) $(NAME)
			$(RM) $(NAME_NCURSES)
			$(RM) $(NAME_SFML)
			$(RM) $(NAME_XLIB)

re:			fclean all

.PHONY:			all clean fclean re
