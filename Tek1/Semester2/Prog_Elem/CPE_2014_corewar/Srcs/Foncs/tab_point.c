/*
** tab_point.c for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 15 18:00:42 2013 moulin_c
** Last update Sun Apr 13 22:54:59 2014 moulin_c
*/

#include "../Includes/flags.h"

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
