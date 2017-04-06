##
## Makefile for Makefile in /home/moulin_c/rendu/Piscine-C-lib/my
## 
## Made by moulin_c
## Login   <moulin_c@epitech.net>
## 
## Started on  Mon Oct 21 10:02:08 2013 moulin_c
## Last update Wed Oct 23 19:57:23 2013 moulin_c
##

NAME =	libmy.a

OBJ =	$(SRC:.c=.o)

SRC =	my_aff_alpha.c \
	my_aff_chiffre.c \
	my_aff_comb.c \
	my_evil_str.c \
	my_factorielle_it.c \
	my_factorielle_rec.c \
	my_find_prime_sup.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_it.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_rev_params.c \
	my_revstr.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlcat.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	cp libmy.a ../libmy.a
	cp my.h ../../Piscine-C-include/my.h

clean:	
	@rm -f $(OBJ)

fclean:	clean 
	@rm $(NAME)

re:	fclean all
