/*
** incantation.c for incantation in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:19:08 2015 Fares Doghri
** Last update Sun Jul  5 23:19:08 2015 Fares Doghri
*/

#include	"server.h"

void		push_incantation(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  if (tmp && check_incantation(p, tmp) == TRUE)
    push_action(&(tmp->actions), incantation, 300/p->delay, p->cmds);
}

void		incantation(t_param *p, t_player *tmp)
{
  if (tmp)
    {
      if (check_incantation(p, tmp) == TRUE)
	up_players(p, tmp);
      else
	dprintf(tmp->id, "niveau actuel : %d\n", tmp->lvl);
    }
}

e_bool		check_incantation(t_param *p, t_player *tmp)
{
  char		str[8];
  char		*lvl[10] = {
    "1100000",
    "2111000",
    "2201020",
    "4112010",
    "4121300",
    "6123010",
    "6222221"
  };

  get_str_incantation(p, tmp, str);
  if (!strcmp(lvl[tmp->lvl - 1], str))
    return (TRUE);
  return (FALSE);
}

void		get_str_incantation(t_param *p, t_player *tmp, char *str)
{
  str[0] = count_players_case(p->players, tmp->y, tmp->x, tmp->lvl) + 48;
  str[1] = count_ressource(p->map[tmp->y][tmp->x], LINEMATE) + 48;
  str[2] = count_ressource(p->map[tmp->y][tmp->x], DERAUMERE) + 48;
  str[3] = count_ressource(p->map[tmp->y][tmp->x], SIBUR) + 48;
  str[4] = count_ressource(p->map[tmp->y][tmp->x], MENDIANE) + 48;
  str[5] = count_ressource(p->map[tmp->y][tmp->x], PHIRAS) + 48;
  str[6] = count_ressource(p->map[tmp->y][tmp->x], THYSTAME) + 48;
  str[7] = 0;
}

void		up_players(t_param *p, t_player *src)
{
  t_player	*tmp;

  tmp = p->players->next;
  while (tmp)
    {
      if (tmp->y == src->y && tmp->x == src->x)
	{
	  ++(tmp->lvl);
	  dprintf(tmp->id, "niveau actuel : %d\n", tmp->lvl);
	}
      tmp = tmp->next;
    }
}
