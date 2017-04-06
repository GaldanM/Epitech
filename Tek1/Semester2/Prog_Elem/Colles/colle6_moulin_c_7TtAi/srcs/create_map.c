/*
** create_map.c for boogle in /home/moulin_c/rendu/colle6_moulin_c_7TtAi/srcs
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jun  2 19:16:16 2014 moulin_c
** Last update Mon Jun  2 20:06:30 2014 moulin_c
*/

#include	<time.h>
#include	<stdlib.h>
#include	"my.h"

int		create_grid(t_param *p)
{
  int		i;

  if ((p->grid = malloc(sizeof(char) * (p->size * p->size + 1))) == NULL)
    return (-1);
  i = 0;
  srand(time(NULL));
  while (i < p->size * p->size)
    {
      p->grid[i] = ((rand() % 24) + 97);
      i++;
    }
  p->grid[i] = '\0';
  return (0);
}

void		fill_grid(t_param *param, t_map *map)
{
  static int	i = 0;
  int		j;

  j = 0;
  while (j < param->size)
    {
      map[j].flag = 0;
      map[j].letter = param->grid[i];
      j++;
      i++;
    }
  map[j].flag = -1;
}

t_map		**create_map(t_param *param)
{
  t_map		**map;
  int		i;

  if (param->grid == NULL)
    if (create_grid(param) == -1)
      return (NULL);
  if ((map = malloc(sizeof(t_map *) * (param->size + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < param->size)
    {
      if ((map[i] = malloc(sizeof(t_map) * (param->size + 1))) == NULL)
	return (NULL);
      fill_grid(param, map[i]);
      i++;
    }
  return (map);
}
