/*
** count_oct_instr.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Count
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 19:27:30 2014 moulin_c
** Last update Sun Apr 13 23:01:42 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/op.h"
#include "../Includes/asm.h"

int	fonct_tab(char **tab, int *oct, int *param)
{
  int	(*fonct[17])(char **, int *, int);

  fonct[0] = my_nothing;
  fonct[1] = my_live;
  fonct[2] = my_ld;
  fonct[3] = my_st;
  fonct[4] = my_add;
  fonct[5] = my_sub;
  fonct[6] = my_and;
  fonct[7] = my_or;
  fonct[8] = my_xor;
  fonct[9] = my_zjmp;
  fonct[10] = my_ldi;
  fonct[11] = my_sti;
  fonct[12] = my_fork;
  fonct[13] = my_lld;
  fonct[14] = my_lldi;
  fonct[15] = my_lfork;
  fonct[16] = my_aff;
  if ((*fonct[param[0]])(tab, oct, param[1]) == -1)
    return (-1);
  return (0);
}

int	count_octet_instr(char **instr, int pos)
{
  int	i;
  int	param[2];
  int	oct;

  i = 0;
  oct = 0;
  while (op_tab[i].mnemonique != NULL)
    {
      if (instr[0] && (my_strcmp(op_tab[i].mnemonique, instr[0]) == 0))
	{
	  param[0] = op_tab[i].code;
	  param[1] = pos;
	  if (fonct_tab(instr, &oct, param) == -1)
	    return (-1);
	  return (oct);
	}
      else
	i++;
    }
  if (op_tab[i].mnemonique == NULL)
    return (-1);
}
