##
## Makefile for  in /home/moulin_c/rendu/NewIRC/IRC
## 
## Made by MOULINNEUF Galdan
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Apr 12 22:52:13 2015 MOULINNEUF Galdan
## Last update Sun Apr 12 22:52:13 2015 MOULINNEUF Galdan
##

# COMPIL

CC		=	gcc

RM		=	rm -f

# FOLDERS

FOLD_SERVER	=	Sources/Server/

FOLD_CLIENT	=	Sources/Client/

# NAMES

NAME_SERVER	=	server

NAME_CLIENT	=	client

## FLAGS

CFLAGS		+=	-W -Wall -Wextra -I ./Includes

## SOURCES

SRCS_SERVER	=	$(FOLD_SERVER)change_nick.c \
			$(FOLD_SERVER)client_read.c \
			$(FOLD_SERVER)displays.c \
			$(FOLD_SERVER)exec_server.c \
			$(FOLD_SERVER)foncs_list.c \
			$(FOLD_SERVER)fonc_add_client.c \
			$(FOLD_SERVER)init_server.c \
			$(FOLD_SERVER)join_channel.c \
			$(FOLD_SERVER)list_channel.c \
			$(FOLD_SERVER)list_client.c \
			$(FOLD_SERVER)main.c \
			$(FOLD_SERVER)quit_channel.c \
			$(FOLD_SERVER)send_msg.c \
			$(FOLD_SERVER)server_read.c \
			$(FOLD_SERVER)str_to_tab.c

SRCS_CLIENT	=	$(FOLD_CLIENT)main.c

## OBJS

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

## RULES

all:			$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJS_SERVER)
			$(CC) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):		$(OBJS_CLIENT)
			$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean:
			$(RM) $(OBJS_SERVER)
			$(RM) $(OBJS_CLIENT)

fclean:			clean
			$(RM) $(NAME_SERVER)
			$(RM) $(NAME_CLIENT)

re:			fclean all

.PHONY:			all clean fclean re
