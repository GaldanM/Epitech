##
## Makefile for ftp in /home/moulin_c/rendu/PSU_2014_myftp
## 
## Made by Galdan Moulinneuf
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Mar 29 21:15:26 2015 Galdan Moulinneuf
## Last update Sun Mar 29 21:40:20 2015 Galdan Moulinneuf
##

CC		=	gcc

RM		=	rm -f

FOLD_SERV	=	Server/

FOLD_CLIENT	=	Client/

FOLD_FUNCTIONS	=	Functions/

SRCS_SERVER	=	$(FOLD_SERV)main.c \
			$(FOLD_SERV)my_cd.c \
			$(FOLD_SERV)my_cmds.c \
			$(FOLD_SERV)my_get.c \
			$(FOLD_SERV)my_put.c \
			$(FOLD_SERV)server.c \
			$(FOLD_SERV)serv_exec.c \
			$(FOLD_FUNCTIONS)get_next_line.c \
			$(FOLD_FUNCTIONS)my_strtotab.c	\
			$(FOLD_FUNCTIONS)send_receive.c \
			$(FOLD_FUNCTIONS)func_common.c

SRCS_CLIENT	=	$(FOLD_CLIENT)main.c \
			$(FOLD_CLIENT)client.c \
			$(FOLD_CLIENT)my_cd_c.c \
			$(FOLD_CLIENT)my_gpc.c \
			$(FOLD_CLIENT)my_ls_c.c \
			$(FOLD_CLIENT)my_pass_c.c \
			$(FOLD_CLIENT)my_pwd_c.c \
			$(FOLD_CLIENT)my_quit_c.c \
			$(FOLD_CLIENT)my_read_c.c \
			$(FOLD_CLIENT)my_user_c.c \
			$(FOLD_FUNCTIONS)get_next_line.c \
			$(FOLD_FUNCTIONS)my_strtotab.c \
			$(FOLD_FUNCTIONS)send_receive.c \
			$(FOLD_FUNCTIONS)func_common.c

CFLAGS		+=	-W -Wall -Wextra -Werror

CFLAGS		+=	-I ./Includes

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

NAME_SERVER	=	serveur

NAME_CLIENT	=	client

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
