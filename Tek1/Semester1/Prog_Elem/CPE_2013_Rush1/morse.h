/*
** morse.h for morse in /home/moulin_c/rendu/CPE_2013_Rush1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Dec 13 23:31:48 2013 moulin_c
** Last update Sun Dec 15 21:24:54 2013 moulin_c
*/

#ifndef MORSE_H_
# define MORSE_H_
# define SIZE 100

#include <stdlib.h>

typedef struct	s_param_e
{
  int	ret_read;
  int	i;
  int	lenght;
  int	key;
  int	is_read;
  char	buffer[SIZE];
  char	*str;
  int	*check_malloc;
}		t_param_e;

typedef struct	s_param_d
{
  int	ret_read;
  int	i;
  int	lenght;
  int	key;
  int	is_read;
  char	buffer[100];
  char	*str;
  int	*check_malloc;
}		t_param_d;

typedef struct	s_encode
{
  char	letter;
  char	*code;
}		t_encode;

typedef struct	s_decode
{
  char	letter;
  char	*code;
}		t_decode;

char		*my_strcpy(char *dest, char *src);
void		my_putchar(char d);
void		my_putstr(char *str);
t_param_e	init(t_param_e var);
int		check_encode(char *str);
t_param_e	write_morse(t_param_e var);
int		main();

#endif /* !MORSE_H_ */
