##
## Makefile for minishell in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Wed Dec 11 17:50:48 2013 moulin_c
## Last update Sun Jan  5 15:30:33 2014 moulin_c
##

NAME	=	mysh

SRCS	=	builts.c \
		flags_1.c \
		flags_2.c \
		flags_3.c \
		foncs.c \
		my_getnbr.c \
		my_printf.c \
		my_putchar.c \
		my_putnbrbase.c \
		my_put_nbr.c \
		my_putstr.c \
		my_putstr_rev.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strncat.c \
		my_strncmp.c \
		tab_point.c \
		checks_shell1.c \
		get_paths.c \
		my_str_to_wordtab.c \
		my_show_wordtab.c \
		my_str_to_pathtab.c \
		foncs_tab.c \
		setenv.c \
		my_cd.c \
		get_next_line.c \
		my_free_tab.c \
		main.c

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
