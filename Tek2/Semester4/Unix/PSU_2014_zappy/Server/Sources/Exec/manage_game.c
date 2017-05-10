/*
** manage_game.c for manage_game in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:29:30 2015 Fares Doghri
** Last update Sun Jul  5 23:29:35 2015 Fares Doghri
*/

#include "server.h"

void		decrease_times(t_param *p)
{
  t_player		*tmp1;
  t_egg			*tmp2;

  tmp1 = p->players->next;
  while (tmp1)
    {
      if ((tmp1 = decrease_food_player(p, tmp1)) != NULL)
	{
	  decrease_actions_player(tmp1);
	  tmp1 = tmp1->next;
	}
    }
  tmp2 = p->eggs->next;
  while (tmp2)
    {
      if ((tmp2 = decrease_egg(p, tmp2)) != NULL)
	tmp2 = tmp2->next;
    }
}

void		browse_actions(t_param *p)
{
  t_player		*tmp1;

  tmp1 = p->players->next;
  while (tmp1)
    {
      browse_actions_player(p, tmp1);
      tmp1 = tmp1->next;
    }
}
