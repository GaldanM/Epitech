##
## Makefile for  in /home/moulin_c/Documents
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Sun Jan  5 01:05:27 2014 moulin_c
## Last update Sun Apr 13 23:25:57 2014 moulin_c
##

NAME		=	asm/asm


FOLD_PARS	=	Srcs/Parser/

FOLD_COUNT	=	Srcs/Count/

FOLD_FONCS	=	Srcs/Foncs/

FOLD_WRITE	=	Srcs/Write/

WRITE		=	$(FOLD_WRITE)make_cor.c \
			$(FOLD_WRITE)oct_cod.c \
			$(FOLD_WRITE)put_in_file.c \
			$(FOLD_WRITE)rev_str.c \
			$(FOLD_WRITE)write_instr.c

PARSER		=	$(FOLD_PARS)add_instr.c \
			$(FOLD_PARS)add_label.c \
			$(FOLD_PARS)check_line.c \
			$(FOLD_PARS)check_instr.c \
			$(FOLD_PARS)epur_str.c \
			$(FOLD_PARS)get_instructions.c \
			$(FOLD_PARS)get_next_line.c \
			$(FOLD_PARS)make_instr.c \
			$(FOLD_PARS)make_labels.c \
			$(FOLD_PARS)my_str_to_inst_tab.c \
			$(FOLD_PARS)my_getstr.c \
			$(FOLD_PARS)list_to_tab.c \
			$(FOLD_PARS)my_calc_labels.c \
			$(FOLD_PARS)parser.c \
			$(FOLD_PARS)recup_header.c \
			$(FOLD_PARS)split_line.c \
			$(FOLD_PARS)my_extension.c

COUNT		=	$(FOLD_COUNT)count1.c \
			$(FOLD_COUNT)count2.c \
			$(FOLD_COUNT)count3.c \
			$(FOLD_COUNT)count4.c \
			$(FOLD_COUNT)count_oct_instr.c \
			$(FOLD_COUNT)foncs_oct.c \
			$(FOLD_COUNT)my_checks.c \
			$(FOLD_COUNT)my_check_type.c

FONCS		=	$(FOLD_FONCS)foncs.c \
			$(FOLD_FONCS)tab_point.c \
			$(FOLD_FONCS)flags_1.c \
			$(FOLD_FONCS)flags_2.c \
			$(FOLD_FONCS)flags_3.c \
			$(FOLD_FONCS)my_printf.c \
			$(FOLD_FONCS)my_put_nbr.c \
			$(FOLD_FONCS)my_putstr.c \
			$(FOLD_FONCS)my_putstr_rev.c \
			$(FOLD_FONCS)my_putnbrbase.c \
			$(FOLD_FONCS)my_getnbr.c \
			$(FOLD_FONCS)my_strcat.c \
			$(FOLD_FONCS)my_strncat.c \
			$(FOLD_FONCS)my_strcmp.c \
			$(FOLD_FONCS)my_strcpy.c \
			$(FOLD_FONCS)my_strdup.c \
			$(FOLD_FONCS)my_strncmp.c \
			$(FOLD_FONCS)my_strlen.c \
			$(FOLD_FONCS)my_putchar.c \
			$(FOLD_FONCS)op.c

OBJS		=	$(PARSER:.c=.o) \
			$(COUNT:.c=.o) \
			$(WRITE:.c=.o) \
			$(FONCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			@cc -o $(NAME) $(OBJS) -g

clean:
			rm -f $(OBJS)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
