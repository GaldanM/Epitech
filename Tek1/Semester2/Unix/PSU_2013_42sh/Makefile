##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Sun Jun  1 18:31:16 2014 doghri_f
##

CC		=	gcc

RM		=	rm -f

INC		=	-I ./Includes

CFLAGS		+=	$(INC) -ggdb

CFLAGS		+=	-Wall -Wextra -Werror

FOLD_LIB	=	cd Lib/Sources/

FOLD_PARSER	=	Parser/

FOLD_LISTS	=	Foncs_lists/

FOLD_SHELL	=	Shell/

FOLD_BUILTS	=	Builts/

LIB		=	-L ./Lib -lmy

NAME		=	42sh

SRCS_PARSER	=	$(FOLD_PARSER)get_cmds.c \
			$(FOLD_PARSER)foncs_get_cmds.c \
			$(FOLD_PARSER)get_env.c \
			$(FOLD_PARSER)get_fds.c \
			$(FOLD_PARSER)redir.c \
			$(FOLD_PARSER)redir2.c \
			$(FOLD_PARSER)redir_foncs.c \
			$(FOLD_PARSER)displays.c \
			$(FOLD_PARSER)syntax_invers.c \
			$(FOLD_PARSER)str_to_syntaxlist.c \
			$(FOLD_PARSER)str_to_wordlist.c \
			$(FOLD_PARSER)sort_syntax.c \
			my_init_env.c \
			main.c

SRCS_LISTS	=	$(FOLD_LISTS)make_lists.c \
			$(FOLD_LISTS)add_lists.c \
			$(FOLD_LISTS)del_lists.c

SRCS_SHELL	=	$(FOLD_SHELL)exec.c \
			$(FOLD_SHELL)list_to_tab.c \
			$(FOLD_SHELL)get_paths.c \
			$(FOLD_SHELL)check_exec.c \
			$(FOLD_SHELL)my_check_builts.c \
			$(FOLD_SHELL)my_sig_shell.c

SRCS_BUILTS	=	$(FOLD_BUILTS)my_cd.c \
			$(FOLD_BUILTS)my_setenv.c \
			$(FOLD_BUILTS)my_unsetenv.c \
			$(FOLD_BUILTS)my_env.c \
			$(FOLD_BUILTS)my_echo.c \
			$(FOLD_BUILTS)my_echo_rest.c \
			$(FOLD_BUILTS)cd_dots.c \
			$(FOLD_BUILTS)my_cd_rest.c

SRCS		=	$(SRCS_PARSER) \
			$(SRCS_LISTS) \
			$(SRCS_SHELL) \
			$(SRCS_BUILTS)

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)
			@echo -e "\033[1;31m\n\t\t\t\t\t\t\t\t\t==== All done ====\n\033[0m"

$(NAME):		$(OBJS)
			@echo -e "\033[1;31m\n\t\t\t\t\t\t\t\t\t==== Starting Compilation ====\n\033[0m"
			$(FOLD_LIB) ; make
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
			@echo -e "\033[1;32m\n\t\t\t\t\t\t\t\t\t==== Cleaning ... ====\n\033[0m"

			$(RM) $(OBJS)
			@echo -e "\033[1;32m\n\t\t\t\t\t\t\t\t\t==== Clean done ====\n\033[0m"

fclean:			clean
			$(RM) $(NAME)
			@echo -e "\033[1;32m\n\t\t\t\t\t\t\t\t\t==== Fclean done ====\n\033[0m"
re:			fclean all

.PHONY:			all clean fclean re
