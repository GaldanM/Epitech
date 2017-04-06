/*
** main.c for boogle in /home/moulin_c/rendu/colle6_moulin_c_7TtAi/srcs
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jun  2 20:02:27 2014 moulin_c
** Last update Mon Jun  2 20:17:35 2014 moulin_c
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my.h"

void		aff_map(t_map **map)
{
  int		i;
  int		j;

  i = 0;
  while (i < 4)
    {
      j = 0;
      while (j < 4)
	{
	  putchar(map[i][j].letter);
	  j++;
	}
      putchar('\n');
      i++;
    }
}

int		main(int argc, char **argv)
{
  t_param	param;
  t_map		**map;

  (void)argc;
  param.grid = NULL;
  param.size = 4;
  param.word = argv[1];
  param.color = 0;
  if ((map = create_map(&param)) == NULL)
    {
      puts("Malloc failed");
      return (-1);
    }
  aff_map(map);
  putchar('\n');
  my_boogle(map, &param);
  return (0);
}
