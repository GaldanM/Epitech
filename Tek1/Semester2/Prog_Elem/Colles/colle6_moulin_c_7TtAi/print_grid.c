/*
** print_grid.c for my_boogle in /home/sement_s/rendu/colle6_moulin_c_7TtAi
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon Jun  2 22:16:41 2014 Stephen SEMENT
** Last update Mon Jun  2 22:29:11 2014 Stephen SEMENT
*/

#include	"my.h"

int		print_upbot(t_param *param)
{
  int		i;

  i = 0;
  my_putchar('+');
  while (i != (size * 2) + 1)
    {
      my_putchar('-');
      i = i + 1;
    }
  my_putchar('+');
  return (0);
}

int		print_grid(t_map **map, t_param *param)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  print_upbot(param);
  while (map[i][j].letter != '\0')
    {
      my_putchar('| ');
      while (j < param.size)
	{
	  my_putchar(map[i][j].letter);
	  my_putchar(' ');
	  j = j + 1;
	}
      my_putchar('|');
      j = 0;
      i = i + 1;
    }
  print_upbot(param);
  return (0);
}
