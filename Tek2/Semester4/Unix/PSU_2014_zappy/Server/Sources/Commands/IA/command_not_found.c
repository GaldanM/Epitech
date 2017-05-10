/*
** command_not_found.c for command_not_found in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Commands/IA
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:20:14 2015 Fares Doghri
** Last update Sun Jul  5 23:20:14 2015 Fares Doghri
*/

# include "server.h"

void		push_command_not_found(t_param *p, int id)
{
  t_player	*tmp;

  tmp = p->players;
  while (tmp && tmp->id != id)
    tmp = tmp->next;
  push_action(&(tmp->actions), command_not_found, 0, p->cmds);
}

void		command_not_found(t_param *p, t_player *tmp)
{
  (void)p;
  printf("Client[%d]: Command not found !\n", tmp->id);
  dprintf(tmp->id, "ko\n");
}
