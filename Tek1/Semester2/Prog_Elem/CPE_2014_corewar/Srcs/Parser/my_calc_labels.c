/*
** my_calc_labels.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Write
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Apr  9 17:05:52 2014 moulin_c
** Last update Sun Apr 13 22:11:30 2014 moulin_c
*/

#include "../Includes/asm.h"
#include "../Includes/mylist.h"

int	browse_up(t_lab *tab, t_param *param, char *name)
{
  int	i;
  int	j;
  int	nb;

  i = param->i;
  j = param->j - 1;
  nb = 0;
  while (j >= 0)
    {
      nb = nb - tab[i].inst[j].nb_octet_instr;
      j--;
    }
  if (!my_strcmp(tab[i].name, name))
    return (nb);
  i--;
  while (i >= 0)
    {
      if (!my_strcmp(tab[i].name, name))
	{
	  nb = nb - tab[i].nb_octet_label;
	  return (nb);
	}
      nb = nb - tab[i--].nb_octet_label;
    }
  return (1);
}

int	browse_down(t_lab *tab, t_param *param, char *name)
{
  int	i;
  int	j;
  int	nb;

  i = param->i;
  j = param->j;
  nb = 0;
  while (tab[i].inst[j].instr != NULL)
    {
      nb = nb + tab[i].inst[j].nb_octet_instr;
      j++;
    }
  i++;
  while (tab[i].inst != NULL)
    {
      if (!my_strcmp(tab[i].name, name))
	return (nb);
      nb = nb + tab[i].nb_octet_label;
      i++;
    }
  return (-1);
}

int	find_labels(t_lab *tab, t_param *param, char *name)
{
  param->lbl = browse_down(tab, param, name);
  if (param->lbl == -1)
    {
      param->lbl = browse_up(tab, param, name);
      if (param->lbl == 1)
	show_error(name, tab[param->i].inst[param->j].pos, "label undefined");
      else
	return (param->lbl);
    }
  return (param->lbl);
}

void	my_calc_labels(t_lab *tab)
{
  t_param	param;

  param.i = 0;
  while (tab[param.i].inst != NULL)
    {
      param.j = 0;
      while (tab[param.i].inst[param.j].instr != NULL)
	{
	  param.k = 0;
	  while (tab[param.i].inst[param.j].instr[param.k] != NULL)
	    {
	      if (!my_strncmp(tab[param.i].inst[param.j].instr[param.k], "%:", 2))
		{
		  param.lbl = find_labels(tab, &param, tab[param.i].inst[param.j].instr[param.k] + 2);
        	  tab[param.i].inst[param.j].instr[param.k] = my_getstr(param.lbl);
		}
	      (param.k)++;
	    }
	  (param.j)++;
	}
      (param.i)++;
    }
}
