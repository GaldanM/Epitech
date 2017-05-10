/*
** my.h for my_h in /home/moulin_c/rendu/Piscine-C-include
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct 11 20:43:21 2013 moulin_c
** Last update Sun May 25 07:48:17 2014 moulin_c
*/

#ifndef MY_H_
# define MY_H_

int	my_epur_strlen(char *str);
char	*malloc_epur(char *str);
char	*epur_str(char *str);

char    *my_strupcase(char *str);

char    *my_strncpy(char *dest, char *src, int nb);

char	*my_strncat(char *dest, char *src, int nb);

int	my_strlen(char *str);

int     my_str_isprintable(char *str);

int     my_str_islower(char *str);

char	*my_strdup(char *src);

char	*my_strndup(char *src, int nb);

int	my_strcmp(char *s1, char *s2);

char	*my_strcapitalize(char *str);

void	my_revstr(char *str);

void	my_putstr_rev(char *str);

void	calcul_putnbr(int nb);
void	my_put_nbr(int nb);

int	my_putchar(char d);

int	calcul_power_it(int power, int nb);
int	my_power_it(int nb, int power);

int	my_isneg(int n);

int	my_find_prime_sup(int nb);

int	my_factorielle_it(int nb);

int	calcul_getnbr(char *str, int i, int j, int sign);
int	my_getnbr(char *str);

int	my_is_prime(int nb);

int	checks_getnbrbase(char *str, char *base);
int	find_pos(char letter, char *base);
int	get_nbr_base(char *str, int len_base, char *base);
int	my_getnbr_base(char *str, char *base);

int	put_converted(unsigned int nb, unsigned int save, int i, char *base);
int	my_putnbrbase(unsigned int nb, char *base);
int	my_putstr(char *str);

int	my_square_root(int nb);

char	*my_strcat(char *dest, char *src);

char	*my_strcpy(char *dest, char *src);

int	my_str_isalpha(char *str);

int	my_str_isnum(char *str);

int	my_str_isupper(char *str);

char	*my_strlowcase(char *str);

int	my_strncmp(char *s1, char *s2, int n);

void	my_find_strstr(char *str, char *to_find, int *key, int *save);
char	*my_strstr(char *str, char *to_find);

int	putstr_fd(char *str, int fd);
int	write_to_fd(char d, int fd);

void	my_swap(void *a, void *b);

#endif /* !MY_H_ */
