##
## Makefile for MAkefile in /home/doghri_f/RUSH_NO_WAY
## 
## Made by doghri_f
## Login   <doghri_f@epitech.net>
## 
## Started on  Sat May 10 19:43:26 2014 doghri_f
## Last update Sun May 11 21:19:08 2014 moulin_c
##

CC		=	gcc

RM		=	rm -f

INC		=	./Includes

LIB_SERVER	=	./Lib/LibNetworkBocalServer.a

LIB_CLIENT	=	./Lib/LibNetworkBocalClient.a

FOLD_SERVER	=	Server/

FOLD_CLIENT	=	Client/

FOLD_EDITOR	=	Editor/

CFLAGS		+=	-I$(INC)

NAME_SERVER	=	js_server

NAME_CLIENT	=	fantasy_client

NAME_EDITOR	=	epic_editor

SRCS_CLIENT	=	$(FOLD_CLIENT)main_client.c

SRCS_EDITOR	=	$(FOLD_EDITOR)get_foncs.c \
			$(FOLD_EDITOR)get_next_line.c \
			$(FOLD_EDITOR)header_file.c \
			$(FOLD_EDITOR)list_parser.c \
			$(FOLD_EDITOR)my_putnbr_param.c \
			$(FOLD_EDITOR)my_putstr_file.c \
			$(FOLD_EDITOR)my_recup_name.c \
			$(FOLD_EDITOR)my_verif_nbr.c \
			$(FOLD_EDITOR)parser.c \
			$(FOLD_EDITOR)rev_str.c \
			$(FOLD_EDITOR)set_foncs.c

SRCS_SERVER	=	$(FOLD_SERVER)main_server.c \
			$(FOLD_SERVER)make_lists.c \
			$(FOLD_SERVER)fill_lists.c \
			$(FOLD_SERVER)server.c \
			$(FOLD_SERVER)get_next_line.c \
			$(FOLD_SERVER)add_lists.c

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

OBJS_EDITOR	=	$(SRCS_EDITOR:.c=.o)

all:			$(NAME_SERVER) $(NAME_CLIENT) $(NAME_EDITOR)

$(NAME_SERVER):		$(OBJS_SERVER)
			$(CC) $(OBJS_SERVER) -o $(NAME_SERVER) $(LIB_SERVER) $(LIB_CLIENT)

$(NAME_CLIENT):		$(OBJS_CLIENT)
			$(CC) $(OBJS_CLIENT) -o $(NAME_CLIENT) $(LIB_CLIENT)

$(NAME_EDITOR):		$(OBJS_EDITOR)
			$(CC) $(OBJS_EDITOR) -o $(NAME_EDITOR)
clean:
			$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_EDITOR)

fclean:			clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_EDITOR)

re:			fclean all

.PHONY:			all clean fclean re
