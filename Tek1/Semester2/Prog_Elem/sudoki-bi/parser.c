/*
** parser.c for Sud-au-cul in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Rush_Sudo
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Feb 28 21:17:25 2014 moulin_c
** Last update Sun Mar  2 20:12:42 2014 moulin_c
*/

#include "sudoku.h"
#include "get_next_line.h"

int	parsing(t_sudo ***tab, char *str, int i)
{
  int	j;
  int	k;

  if ((tab[0][i] = malloc(sizeof(t_sudo) * 9)) == NULL)
    return (-1);
  j = 0;
  k = 2;
  while (k < 20)
    {
      if ((str[k] < 48 || str[k] > 57) && str[k] != ' ')
	return (-1);
      if (str[k] == ' ')
	{
	  tab[0][i][j].num = 0;
	  tab[0][i][j++].key = 0;
	}
      else
	{
	  tab[0][i][j].num = str[k] - 48;
	  tab[0][i][j++].key = 1;
	}
      k = k + 2;
    }
  free(str);
  return (0);
}

int	parser(t_sudo ***tab, char *str)
{
  int	i;
  int	k;
  int	m;

  if ((tab[0] = malloc(sizeof(t_sudo *) * 9)) == NULL)
    return (-1);
  while (str)
    {
      i = 0;
      while (i < 9)
	{
	  str = get_next_line(0);
	  if (!str)
	    return (-1);
	  if (parsing(tab, str, i) == -1)
	    return (-1);
	  if (!tab[0])
	    return (-1);
	  i++;
	}
      str = get_next_line(0);
      return (0);
    }
}
