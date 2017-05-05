##
## Makefile for  in /home/teyssa_r/rendu/malloc
##
## Made by Raphael Teyssandier
## Login   <teyssa_r@epitech.net>
##
## Started on  Sat Feb 7 14:28:05 2015 Raphael Teyssandier
## Last update Fri Feb 13 19:11:21 2015 Galdan MOULINNEUF
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wpadded -Werror

CFLAGS	+= -fPIC

NAME	= malloc

LIBNAME	= libmy_malloc_$(HOSTTYPE).so

MYLIB	= libmy_malloc.so

SRCS	= free.c \
	  malloc.c \
	  show_alloc.c \
	  realloc.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -c -fPIC $(SRCS) $(CFLAGS)
	@$(CC) -shared -o $(LIBNAME) $(OBJS)
	@ln -f $(LIBNAME) $(MYLIB)
	$(COMPIL_ING)

%.o:	%.c
	$(DOT_O_S)
	@$(CC) $(CFLAGS) -c -o $@ $^
	$(DOT_O_E)

clean:
	@$(RM) $(OBJS)
	$(CLEAN_R)

fclean: clean
	@$(RM) $(NAME)
	$(FCLEAN_R)

re:	fclean all

.PHONY: all clean fclean re

define DOT_O_S
	@tput setaf 3
	@tput bold
	@printf "Compiling \t"
	@tput setaf 4
	@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
endef

define COMPIL_ING
	@tput setaf 7
	@tput bold
	@tput cuf 26
	@printf "\e[3mCompiling Done\e[0m"
	@tput setaf 1
	@tput bold
	@tput cuf 25
	@printf "\e[3mAstek <3\e[0m\n"
endef

define DOT_O_E
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setf 2
	@tput bold
	@printf "√"
	@tput sgr0
	@printf " ]\n"
endef

define CLEAN_R
	@tput clear
	@tput cuf 16
	@tput bold
	@tput setaf 6
	@printf "######################################\n"
	@tput cuf 16
	@printf "#                                    #\n"
	@tput cuf 16
	@printf "#              "
	@tput setaf 7
	@printf "\e[5mMalloc\e[0m"
	@tput setaf 6
	@tput bold
	@printf "                #\n"
	@tput cuf 16
	@printf "#        "
	@tput setaf 1
	@tput smul
	@tput bold
	@printf "\e[3mMakefile to the Futur"
	@tput rmul
	@tput setaf 6
	@tput bold
	@printf "       #\n"
	@tput cuf 16
	@printf "#                                    #\n"
	@tput cuf 16
	@printf "######################################\n"
	@tput setaf 7
	@tput bold
	@tput smul
	@printf "\e[3mRemoving Binary\e[0m\n"
	@tput rmul
	@tput setaf 1
	@tput bold
	@tput rmul
	@printf "Removing  \t"
	@tput setaf 4
	@printf "File [.o]...\n"
	@tput sgr0
	@tput cuf 68
	@tput cuu1
	@printf "[ "
	@tput setaf 1
	@tput bold
	@printf "√"
	@tput sgr0
	@printf " ]\n"
endef

define FCLEAN_R
	@tput setaf 7
	@tput bold
	@tput smul
	@printf "\e[3mRemoving File\e[0m\n"
	@tput rmul
	@tput setaf 1
	@tput bold
	@printf "Removing  \t"
	@tput setaf 4
	@printf "File %s...\n", $(NAME)
	@tput sgr0
	@tput cuf 67
	@tput cuu1
	@printf "[ "
	@tput setaf 1
	@tput bold
	@printf "√"
	@tput sgr0
	@printf " ]\n"

endef
