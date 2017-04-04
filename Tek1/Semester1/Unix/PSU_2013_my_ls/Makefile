##
## Makefile for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Dec  1 19:04:16 2013 moulin_c
## Last update Sun Dec  1 19:16:04 2013 moulin_c
##

NAME	=	my_ls

SRC	=	flags_1.c \
		flags_2.c \
		flags_3.c \
		foncs.c \
		ls_count_files.c \
		ls_mod_date.c \
		ls_nb_block.c \
		ls_rights.c \
		ls_sort_alpha.c \
		ls_sort_alpha_rev.c \
		ls_tab_flags.c \
		ls_tab_name.c \
		ls_tab_name_rev.c \
		main.c \
		my_ls_a.c \
		my_ls_big_r.c \
		my_ls.c \
		my_ls_d.c \
		my_ls_file.c \
		my_ls_l.c \
		my_ls_other.c \
		my_ls_r.c \
		my_ls_t.c \
		my_printf.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putnbrbase.c \
		my_putstr.c \
		my_putstr_rev.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlen.c \
		tab_point.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		@cc -o $(NAME) $(OBJ)

clean:		
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

PHONY:		all clean fclean re
