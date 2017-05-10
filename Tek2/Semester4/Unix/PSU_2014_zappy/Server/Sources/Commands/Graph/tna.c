/*
** tna.c for tna in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:23:14 2015 Fares Doghri
** Last update Sun Jul  5 23:23:15 2015 Fares Doghri
*/

#include "server.h"

void 		tna(t_param *p, int id, int id_p)
{
  char	*team;
  int		i;

  (void)id_p;
  team = "";
  i = 0;
  while (p->team_name[i])
    {
      if (asprintf(&team, "%stna %s\n", team, p->team_name[i]) == -1)
	return ;
      i++;
    }
  dprintf(id, "%s", team);
}
