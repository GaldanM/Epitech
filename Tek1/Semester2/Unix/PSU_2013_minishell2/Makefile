##
## Makefile for minishell in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Wed Dec 11 17:50:48 2013 moulin_c
## Last update Sun Mar  9 21:30:21 2014 moulin_c
##

NAME	=	mysh

SRCS	=	Builts/builts.c \
		Builts/my_setenv.c \
		Builts/my_cd.c \
		Lib/flags_1.c \
		Lib/flags_2.c \
		Lib/flags_3.c \
		Lib/foncs.c \
		Lib/get_next_line.c \
		Lib/my_getnbr.c \
		Lib/my_printf.c \
		Lib/my_putchar.c \
		Lib/my_putnbrbase.c \
		Lib/my_put_nbr.c \
		Lib/my_putstr.c \
		Lib/my_putstr_rev.c \
		Lib/my_strcat.c \
		Lib/my_strcmp.c \
		Lib/my_strcpy.c \
		Lib/my_strdup.c \
		Lib/my_strlen.c \
		Lib/my_strncat.c \
		Lib/my_strncmp.c \
		Lib/tab_point.c \
		Parser/foncs_redir.c \
		Parser/foncs_tab.c \
		Parser/my_free_tab.c \
		Parser/my_show_wordtab.c \
		Parser/my_str_to_pathtab.c \
		Parser/my_str_to_wordtab.c \
		Parser/parser.c \
		Shell/checks_shell.c \
		Shell/get_paths.c \
		Shell/my_exec.c \
		Shell/main.c

OBJ	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@cc -o $(NAME) $(OBJ) -g

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
