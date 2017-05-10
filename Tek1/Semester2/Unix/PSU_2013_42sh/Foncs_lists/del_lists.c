/*
** del_lists.c for lemin in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Lem-in/CPE-2014-lem_in
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu May  1 20:03:38 2014 moulin_c
** Last update Sun Jun  1 18:32:22 2014 doghri_f
*/

#include	<stdlib.h>
#include	"lists.h"

void		del_env(t_env *del)
{
  t_env		*elem;

  elem = del;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
}

void		del_cmd(t_cmds *del)
{
  t_cmds	*elem;

  elem = del;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
}

void		del_arg(t_args *del)
{
  t_args	*elem;

  elem = del;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
}

void		del_syntax(t_syntax *del)
{
  t_syntax	*elem;

  elem = del;
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
}
