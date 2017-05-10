/*
** get_str_look.c for get_str_look in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:22:23 2015 Fares Doghri
** Last update Sun Jul  5 23:22:27 2015 Fares Doghri
*/

#include "server.h"

char			*get_str_case(t_param *p, int y, int x, char *send)
{
  t_case		*tmp;
  char 		*res[12] = {"nourriture", "linemate",
			    "deraumere", "sibur", "mendiane",
			    "phiras", "thystame"};

  tmp = p->map[y][x]->next;
  if ((send = get_str_players(p->players, y, x, send)) == NULL)
    return (NULL);
  while (tmp)
    {
      if (((send = my_strcat(send, " ")) == NULL)
	  || ((send = my_strcat(send, res[tmp->ressource])) == NULL))
	return (NULL);
      tmp = tmp->next;
    }
  return (send);
}

char			*get_str_players(t_player *players, int y, int x, char *send)
{
  t_player	*tmp;

  tmp = players->next;
  while (tmp)
    {
      if (tmp->y == y && tmp->x == x)
	{
	  if ((send = my_strcat(send, " joueur")) == NULL)
	    return (NULL);
	}
      tmp = tmp->next;
    }
  return (send);
}
