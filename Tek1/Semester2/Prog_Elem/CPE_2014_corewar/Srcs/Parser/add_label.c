/*
** my_put_in_list_end.c for my_put_in_list_end in /home/moulin_c/rendu/Piscine-C-Jour_12/test
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct 22 15:57:27 2013 moulin_c
** Last update Sun Apr 13 21:46:40 2014 moulin_c
*/

#include "../Includes/mylist.h"
#include "../Includes/asm.h"

int		add_label(t_labels **label, t_instr *inst, t_save save, int nb)
{
  t_labels	*elem;
  t_labels	*tmp;

  tmp = *label;
  if ((elem = malloc(sizeof(t_labels))) == NULL)
    return (-1);
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->instr = inst;
  elem->name = save.name;
  elem->pos = save.pos_label;
  elem->nb_octet = nb;
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
