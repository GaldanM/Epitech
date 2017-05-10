/*
** bct_case.c for bct_case in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/Graph
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:25:24 2015 Fares Doghri
** Last update Sun Jul  5 23:26:28 2015 Fares Doghri
*/

#include "server.h"

char 		*get_case(t_param *p, int x, int y)
{
  int		c0;
  int		c1;
  int		c2;
  int		c3;
  char	*cmd;

  cmd = NULL;
  if (asprintf(&cmd, "bct %d %d", x, y) == -1)
    return (NULL);
  c0 = count_ressource(p->map[y][x], NOURRITURE);
  c1 = count_ressource(p->map[y][x], LINEMATE);
  c2 = count_ressource(p->map[y][x], DERAUMERE);
  c3 = count_ressource(p->map[y][x], SIBUR);
  if (asprintf(&cmd, "%s %d %d %d %d", cmd, c0, c1, c2, c3) == -1)
    return (NULL);
  c1 = count_ressource(p->map[y][x], MENDIANE);
  c2 = count_ressource(p->map[y][x], PHIRAS);
  c3 = count_ressource(p->map[y][x], THYSTAME);
  if (asprintf(&cmd, "%s %d %d %d\n", cmd, c1, c2, c3) == -1)
    return (NULL);
  return (cmd);
}

void 		bct_case(t_param *p, int id, int id_p)
{
  char	*str;

  (void)id_p;
  if ((str = get_case(p, atoi(p->cmds[1]), atoi(p->cmds[2]))) != NULL)
    dprintf(id, "%s", str);
}
