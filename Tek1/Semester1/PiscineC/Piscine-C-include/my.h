/*
** my.h for my_h in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct 11 20:43:21 2013 moulin_c
** Last update Mon Oct 21 10:56:53 2013 moulin_c
*/

#ifndef MY_H_
# define MY_H_

void	my_putchar(char d);
int	my_aff_alpha();
int	my_aff_revalpha();
int	my_aff_chiffre();
int	my_isneg(int n);
int	my_aff_comb();
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_evil_str(char *str);
int	my_getnbr(char *str);
int	my_factorielle_it(int nb);
int	my_factorielle_rec(int nb);
int	my_power_it(int nb, int power);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	*my_strdup(char *src);

#endif /*!MY_H_ */
