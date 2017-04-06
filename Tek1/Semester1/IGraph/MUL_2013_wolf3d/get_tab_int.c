/*
** get_tab_int.c for wolf3d in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  8 11:40:23 2014 moulin_c
** Last update Sun Jan 12 01:56:38 2014 moulin_c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "wolf.h"

int		my_strlen_tab_int(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[count])
    {
      if (str[count] != ' ' && str[count] != '\t')
	i++;
      count++;
    }
  return (i);
}

int		get_y_len(char *str, int *y, int fd)
{
  char	*s;

  while ((s = get_next_line(fd)))
    {
      if (s == NULL)
	{
	  my_putstr("Wrong MAP format\n");
	  return (-1);
	}
      (*y)++;
      free(s);
    }
  if (close(fd) == -1)
    {
      my_putstr("CLOSE FAILED\n");
      return (-1);
    }
}

int		get_len(char *str, int *x, int *y)
{
  int		fd;
  char		*s;

  *x = 0;
  *y = 0;
  if ((fd = open(str, O_RDONLY | O_APPEND, S_IRUSR)) == -1)
    {
      my_putstr("Wrong MAP file\n");
      return (-1);
    }
  if ((s = get_next_line(fd)) == NULL)
    {
      my_putstr("Wrong MAP format\n");
      return (-1);
    }
  *x = my_strlen_tab_int(s);
  (*y)++;
  free(s);
  if (get_y_len(str, y, fd) == -1)
    return (-1);
  return (0);
}

int		my_str_to_tabint(char *str, int x, char **tab)
{
  int		i;
  int		m;
  static int	j = 0;

  i = 0;
  m = 0;
  if ((tab[j] = malloc(sizeof(char) * (x + 1))) == NULL)
    return (-1);
  while (str[i])
    {
      while ((str[i] == ' ' || str[i] == '\t') && str[i])
	i++;
      tab[j][m] = str[i] - 48;
      m++;
      i++;
    }
  tab[j][m] = -2;
  j++;
  return (j);
}

char		**get_tab_int(char *str)
{
  char		**tab;
  int		fd;
  int		x;
  int		y;
  int		j;

  if (get_len(str, &x, &y) == -1)
    return (NULL);
  if ((tab = malloc(sizeof(char *) * (y + 1))) == NULL)
    return (NULL);
  if ((fd = open(str, O_APPEND | O_RDONLY, S_IRUSR)) == -1)
    return (NULL);
  while ((str = get_next_line(fd)))
    {
      if (str == NULL)
	return (NULL);
      if ((j = my_str_to_tabint(str, x, tab)) == -1)
	return (NULL);
      free(str);
    }
  tab[j] = 0;
  if (close(fd) == -1)
    return (NULL);
  return (tab);
}
