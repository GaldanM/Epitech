/*
** browse_look.c for browse_look in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:21:22 2015 Fares Doghri
** Last update Sun Jul  5 23:21:30 2015 Fares Doghri
*/

#include		"server.h"

char			*browse_north(t_p_look *pa, char *send)
{
  int			i;

  while (pa->r_y <= pa->r_max)
    {
      i = 0;
      if ((pa->x = pa->tmp->x - pa->r_x) < 0)
	pa->x = pa->p->size_x - 1;
      while (i < pa->r_y)
	{
	  if ((send = get_str_case(pa->p, pa->y, pa->x, send)) == NULL)
	    return (NULL);
	  if (i + 1 < pa->r_y || pa->r_y + 2 <= pa->r_max)
	    if ((send = my_strcat(send, ",")) == NULL)
	      return (NULL);
	  ++i;
	  if (++(pa->x) > pa->p->size_x - 1)
	    pa->x = 0;
	}
      pa->r_y += 2;
      ++(pa->r_x);
      if (--(pa->y) < 0)
	pa->y = pa->p->size_y - 1;
    }
  return (send);
}

char			*browse_east(t_p_look *pa, char *send)
{
  int			i;

  while (pa->r_x <= pa->r_max)
    {
      i = 0;
      if ((pa->y = pa->tmp->y - pa->r_y) < 0)
	pa->y = pa->p->size_y - 1;
      while (i < pa->r_x)
	{
	  if ((send = get_str_case(pa->p, pa->y, pa->x, send)) == NULL)
	    return (NULL);
	  if (i + 1 < pa->r_x || pa->r_x + 2 <= pa->r_max)
	    if ((send = my_strcat(send, ",")) == NULL)
	      return (NULL);
	  ++i;
	  if (++(pa->y) > pa->p->size_y - 1)
	    pa->y = 0;
	}
      pa->r_x += 2;
      ++(pa->r_y);
      if (++(pa->x) > pa->p->size_x - 1)
	pa->x = 0;
    }
  return (send);
}

char			*browse_west(t_p_look *pa, char *send)
{
  int			i;

  while (pa->r_x <= pa->r_max)
    {
      i = 0;
      if ((pa->y = pa->tmp->y + pa->r_y) > pa->p->size_y - 1)
	pa->y = pa->p->size_y - 1;
      while (i < pa->r_x)
	{
	  if ((send = get_str_case(pa->p, pa->y, pa->x, send)) == NULL)
	    return (NULL);
	  if (i + 1 < pa->r_x || pa->r_x + 2 <= pa->r_max)
	    if ((send = my_strcat(send, ",")) == NULL)
	      return (NULL);
	  ++i;
	  if (--(pa->y) < 0)
	    pa->y = pa->p->size_y - 1;
	}
      pa->r_x += 2;
      ++(pa->r_y);
      if (--(pa->x) < 0)
	pa->x = pa->p->size_x - 1;
    }
  return (send);
}

char			*browse_south(t_p_look *pa, char *send)
{
  int			i;

  while (pa->r_y <= pa->r_max)
    {
      i = 0;
      if ((pa->x = pa->tmp->x + pa->r_x) > pa->p->size_y - 1)
	pa->x = pa->p->size_x - 1;
      while (i < pa->r_y)
	{
	  if ((send = get_str_case(pa->p, pa->y, pa->x, send)) == NULL)
	    return (NULL);
	  if (i + 1 < pa->r_y || pa->r_y + 2 <= pa->r_max)
	    if ((send = my_strcat(send, ",")) == NULL)
	      return (NULL);
	  ++i;
	  if (--(pa->x) < 0)
	    pa->x = pa->p->size_x - 1;
	}
      pa->r_y += 2;
      ++(pa->r_x);
      if (++(pa->y) > pa->p->size_y - 1)
	pa->y = 0;
    }
  return (send);
}
