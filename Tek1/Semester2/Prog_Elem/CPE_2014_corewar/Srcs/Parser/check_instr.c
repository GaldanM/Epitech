/*
** check_instr.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Apr 11 19:09:54 2014 moulin_c
** Last update Sun Apr 13 21:50:28 2014 moulin_c
*/

#include "../Includes/op.h"
#include "../Includes/asm.h"

int	check_mnemo(char **tab, int pos, t_param *param)
{
  int	i;

  i = 0;
  while (tab[0] && op_tab[i].mnemonique != 0 &&
	 (my_strcmp(tab[0], op_tab[i].mnemonique)))
    i++;
  if (op_tab[i].mnemonique == 0)
    show_error(tab[0], pos, "Is not an instruction");
  else
    {
      param->k = 1;
      while (tab[param->k] != NULL)
	{
	  i = 0;
	  while (op_tab[i].mnemonique != 0)
	    {
	      if (!my_strcmp(tab[param->k], op_tab[i].mnemonique))
	  	show_error(tab[param->k], pos, "Two instructions on the same line");
	      i++;
	    }
	  (param->k)++;
	}
    }
  return (0);
}

int	check_instr(t_lab *tab)
{
  t_param	param;

  param.i = 0;
  while (tab[param.i].inst != NULL)
    {
      param.j = 0;
      while (tab[param.i].inst[param.j].instr != NULL)
	{
	  check_mnemo(tab[param.i].inst[param.j].instr,
		      tab[param.i].inst[param.j].pos, &param);
	  (param.j)++;
	}
      (param.i)++;
    }
  return (0);
}
