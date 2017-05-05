/*
** add_lists.c for lemin in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Lem-in/CPE-2014-lem_in
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu May  1 19:51:39 2014 moulin_c
** Last update Sun May 11 20:32:56 2014 moulin_c
*/

#include <stdlib.h>
#include <unistd.h>
#include "fantasy.h"

void		add_champ(t_champs **champs, t_champs *champ)
{
  if (champ->name == NULL)
    my_exitstr("Wrong file");
  champ->prev = (*champs)->prev;
  champ->next = (*champs);
  (*champs)->prev->next = champ;
  (*champs)->prev = champ;
}

void		add_monst(t_monsts **monsts, t_monsts *monst)
{
  if (monst->type == NULL)
    my_exitstr("Wrong file");
  monst->prev = (*monsts)->prev;
  monst->next = (*monsts);
  (*monsts)->prev->next = monst;
  (*monsts)->prev = monst;
}

void		add_room(t_rooms **rooms, t_rooms *room)
{
  if (room->name == NULL)
    my_exitstr("Wrong file");
  room->prev = (*rooms)->prev;
  room->next = (*rooms);
  (*rooms)->prev->next = room;
  (*rooms)->prev = room;
}
