/*
** printf.c for Printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Nov 11 13:54:21 2013 moulin_c
** Last update Fri Apr 18 04:02:09 2014 moulin_c
*/

#include "my_printf.h"

int	my_match(char *str, int i)
{
  char	flags[14];
  int	n;

  n = 0;
  flags[0] = 'i';
  flags[1] = 'd';
  flags[2] = 's';
  flags[3] = 'S';
  flags[4] = 'c';
  flags[5] = 'u';
  flags[6] = 'x';
  flags[7] = 'X';
  flags[8] = 'o';
  flags[9] = 'p';
  flags[10] = '%';
  flags[11] = 'b';
  flags[12] = 'm';
  flags[13] = '\0';
  while (flags[n] != str[i] && flags[n] != '\0')
    n = n + 1;
  return (n);
}

void	tab_flag(va_list arg_pos, char *str, int i)
{
  void	(*tab[14])(va_list arg_pos, char *str, int i);

  tab[0] = &if_i;
  tab[1] = &if_d;
  tab[2] = &if_s;
  tab[3] = &if_bs;
  tab[4] = &if_c;
  tab[5] = &if_u;
  tab[6] = &if_x;
  tab[7] = &if_bx;
  tab[8] = &if_o;
  tab[9] = &if_p;
  tab[10] = &if_percent;
  tab[11] = &if_b;
  tab[12] = &if_m;
  tab[13] = &if_no;
  tab[my_match(str, i)](arg_pos, str, i);
}

int		my_printf(char *str, ...)
{
  va_list	arg_pos;
  int		i;

  i = 0;
  va_start(arg_pos, str);
  while (str[i] != '\0')
   {
      if (str[i] == '%')
	{
	  i = i + 1;
	  while (str[i] == ' ' || str[i] == '-')
	    i = i + 1;
	  if (str[i] == '\0')
	    return (0);
	  tab_flag(arg_pos, str, i);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  va_end(arg_pos);
}
