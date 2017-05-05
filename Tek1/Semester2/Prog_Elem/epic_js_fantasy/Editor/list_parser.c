/*
** list_parser.c for  in /home/medec_o/rendu/rush_game/parser_game
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Sun May 11 10:17:02 2014 medec_o
** Last update Sun May 11 21:36:15 2014 moulin_c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "editor.h"

t_rooms		*make_rooms(void)
{
  t_rooms		*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->name = NULL;
      root->room_id = 0;
      root->prev = root;
      root->root = 1;
      root->next = root;
    }
  else
    exit(3);
  return (root);
}

void		add_room(t_rooms **rooms, int room_nb, char *str)
{
  t_rooms		*elem;

  elem = malloc(sizeof(*elem));
  if (elem != NULL)
    {
      elem->name = str;
      elem->room_id = room_nb;
      elem->prev = (*rooms)->prev;
      elem->next = (*rooms);
      elem->root = 0;
      (*rooms)->prev->next = elem;
      (*rooms)->prev = elem;
    }
  else
    exit(5);
}
