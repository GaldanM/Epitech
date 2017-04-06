/*
** my_put_in_list_end.c for my_put_in_list_end in /home/moulin_c/rendu/Piscine-C-Jour_12/test
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:57:27 2013 moulin_c
** Last update Sun Apr 13 21:44:20 2014 moulin_c
*/

#include "../Includes/mylist.h"
#include "../Includes/asm.h"

int		add_instr(t_instr **instr, char **tab, int nb, t_save *save)
{
  t_instr	*elem;
  t_instr	*tmp;

  tmp = *instr;
  if ((elem = malloc(sizeof(t_instr))) == NULL)
    return (0);
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->inst = tab;
  elem->nb_octet = nb;
  elem->pos = save->pos;
  elem->next = NULL;
  if (tmp->prev == NULL)
    {
      elem->prev = tmp;
      tmp->next = elem;
    }
  else
    {
      elem->prev = tmp;
      tmp->next = elem;
    }
  return (0);
}
