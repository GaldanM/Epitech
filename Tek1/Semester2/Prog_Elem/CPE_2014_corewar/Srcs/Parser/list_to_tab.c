/*
** list_to_tab.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Write
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Apr  9 21:28:52 2014 moulin_c
** Last update Sun Apr 13 23:34:28 2014 moulin_c
*/

#include "../Includes/asm.h"
#include "../Includes/mylist.h"

int	nb_labels(t_labels *list)
{
  int	nb;

  list = list->next;
  nb = 0;
  while (list != NULL)
    {
      nb++;
      list = list->next;
    }
  return (nb);
}

int	nb_instr(t_instr *list)
{
  int	nb;

  list = list->next;
  nb = 0;
  while (list != NULL)
    {
      nb++;
      list = list->next;
    }
  return (nb);
}

void	fill_tab(t_lab *tab, t_labels *list, int *i, int *j)
{
  tab[*i].inst[*j].instr = list->instr->inst;
  tab[*i].inst[*j].pos = list->instr->pos;
  tab[*i].inst[*j].nb_octet_instr = list->instr->nb_octet;
  (*j)++;
  list->instr = list->instr->next;
}

t_lab	*list_to_tab(t_labels *list)
{
  t_lab	*tab;
  int	i;
  int	j;

  i = 0;
  tab = malloc(sizeof(t_lab) * nb_labels(list) + 10);
  list = list->next;
  while (list != NULL)
    {
      if (tab[i].inst = malloc(sizeof(t_ins) * nb_instr(list->instr) + 50))
	exit(1);
      tab[i].name = list->name;
      tab[i].pos = list->pos;
      tab[i].nb_octet_label = list->nb_octet;
      j = 0;
      list->instr = list->instr->next;
      while (list->instr != NULL)
	fill_tab(tab, list, &i, &j);
      tab[i++].inst[j].instr = NULL;
      list = list->next;
    }
  tab[i].inst = NULL;
  return (tab);
}
