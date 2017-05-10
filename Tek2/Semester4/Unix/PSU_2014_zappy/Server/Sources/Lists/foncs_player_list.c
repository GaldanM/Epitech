/*
** foncs_player_list.c for fonc_player in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Lists
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:33:58 2015 Fares Doghri
** Last update Sun Jul  5 23:34:09 2015 Fares Doghri
*/

#include		"player.h"

t_player		*init_player_list()
{
  t_player	*root;

  root = malloc(sizeof(t_player));
  if (root != NULL)
    {
      srand(time(NULL));
      root->root = 1;
      root->next = NULL;
    }
  return (root);
}

e_bool 			push_player(t_player **root, t_player *src)
{
  t_player	*nouv;

  if ((nouv = malloc(sizeof(t_player))) == NULL)
    {
      fprintf(stderr, "Failed to create new player\n");
      return (FALSE);
    }
  nouv->actions = init_actions();
  init_player(nouv, src);
  nouv->next = (*root)->next;
  (*root)->next = nouv;
  return (TRUE);
}

void		init_player(t_player *nouv, t_player *src)
{
  nouv->y = src->y;
  nouv->x = src->x;
  nouv->id = src->id;
  nouv->team = src->team;
  nouv->time = src->time;
  nouv->direction = N;
  nouv->lvl = 1;
  nouv->status = src->status;
  gettimeofday(&nouv->start, NULL);
  nouv->inventory[NOURRITURE] = 10;
  nouv->inventory[LINEMATE] = 1;
  nouv->inventory[DERAUMERE] = 0;
  nouv->inventory[SIBUR] = 0;
  nouv->inventory[MENDIANE] = 0;
  nouv->inventory[PHIRAS] = 0;
  nouv->inventory[THYSTAME] = 0;
  nouv->sound[0] = 1;
  nouv->sound[1] = 2;
  nouv->sound[2] = 3;
  nouv->sound[3] = 4;
  nouv->sound[4] = 5;
  nouv->sound[5] = 6;
  nouv->sound[6] = 7;
  nouv->sound[7] = 8;
}

e_bool 			delete_player(t_player **root, int id)
{
  t_player	*tmp;
  t_player	*prev;

  prev = *root;
  tmp = (*root)->next;
  while (tmp != NULL && tmp->id != id)
    {
      prev = tmp;
      tmp = tmp->next;
    }
  if (!tmp)
    return (FALSE);
  prev->next = tmp->next;
  free(tmp);
  return (TRUE);
}

int 			count_players_case(t_player *root, int y, int x, int lvl)
{
  int 		nb;
  t_player	*tmp;

  nb = 0;
  tmp = root->next;
  while (tmp)
    {
      if (tmp->y == y && tmp->x == x)
	++nb;
      if (tmp->y == y && tmp->x == x && tmp->lvl != lvl)
	return (10);
      tmp = tmp->next;
    }

  return (nb);
}
