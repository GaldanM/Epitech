/*
** my_boogle.c for boogle in /home/moulin_c/rendu/colle6_moulin_c_7TtAi/srcs
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jun  2 20:17:47 2014 moulin_c
** Last update Mon Jun  2 21:01:52 2014 moulin_c
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"

int		search_nexts(t_map **map, t_param *p, char *word)
{
  if (p->k == my_strlen(word))
    return (2);
  if (p->i - 1 >= 0)
    {
      if (map[p->i - 1][p->j] = word[p->k + 1])
	return (1);
    }
  else if (p->i + 1 <= p->size)
    {
      if (map[p->i + 1][p->j] = word[p->k + 1])
	return (1);
    }
  else if (p->j - 1 >= 0)
    {
      if (map[p->i][p->j - 1] = word[p->k + 1])
	return (1);
    }
  else if (p->j + 1 <= p->size)
    {
      if (map[p->i][p->j + 1] = word[p->k + 1])
	return (1);
    }
  return (0);
}

int		search_first(t_map **map, t_param *p, char *word)
{
  int		i;
  int		j;

  i = p->i;
  j = p->j;
  while (map[i][j].letter != word[0])
    {
      if (j == p->size)
	{
	  j = 0;
	  i++;
	}
      if (i == p->size)
	return (-1);
      j++;
    }
  p->i = i;
  p->j = j;
  printf("i = %d\tj = %d\n", i, j);
  exit(1);
  return (0);
}

int		check_word(t_map **map, t_param *p, char *word)
{
  int		ret;

  ret = 1;
  if (p->word != NULL)
    word = p->word;
  while (!search_first(map, p, word))
    {
      while (ret == 1)
	{
	  if ((ret = search_nexts(map, p, word)) == 2)
	    return (1);
	  (p->k)++;
	}
    }
  return (0);
}

int		my_boogle(t_map **map, t_param *p)
{
  char		*word;

  word = NULL;
  p->key = 0;
  while (p->key == 0)
    {
      if (p->word == NULL)
	if ((word = get_word()) == NULL)
	  return (-1);
      p->key = check_word(map, p, word);
      if (p->key == 0)
	puts("Ne trouve pas");
      else
	puts("Trouvé !");
    }
  return (0);
}
