/*
** make_lists.c for make lists in /home/moulin_c/rendu/epic_js_fantasy/Server
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat May 10 19:34:49 2014 moulin_c
** Last update Sun May 11 20:32:42 2014 moulin_c
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"fantasy.h"

t_rooms		*make_rooms(void)
{
  t_rooms	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->name = NULL;
      root->connect = NULL;
      root->nb_monst = -1;
      root->adv = -1;
      root->next = root;
    }
  else
    my_exitstr("Malloc failed");
  return (root);
}

t_champs	*make_champs(void)
{
  t_champs	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->name = NULL;
      root->type = NULL;
      root->weapon = NULL;
      root->armor = NULL;
      root->hp = -1;
      root->spe = -1;
      root->spd = -1;
      root->deg = -1;
      root->next = root;
    }
  else
    my_exitstr("Malloc failed");
  return (root);
}

t_monsts	*make_monsts(void)
{
  t_monsts	*root;

  root = malloc(sizeof(*root));
  if (root != NULL)
    {
      root->prev = root;
      root->type = NULL;
      root->weapon = NULL;
      root->armor = NULL;
      root->hp = -1;
      root->spe = -1;
      root->spd = -1;
      root->deg = -1;
      root->next = root;
    }
  else
    my_exitstr("Malloc failed");
  return (root);
}
