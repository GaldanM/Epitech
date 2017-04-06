/*
** foncs_oct.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Count
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 19:23:43 2014 moulin_c
** Last update Sun Apr 13 23:00:23 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/mylist.h"
#include "../Includes/op.h"

int		label_size(t_instr *instr)
{
  int		nb;

  instr = instr->next;
  nb = 0;
  while (instr != NULL)
    {
      nb = nb + instr->nb_octet;
      instr = instr->next;
    }
  return (nb);
}

int     direct_char_err(char *tab, int pos, int i)
{
  if (tab[i] == '%' && tab[i + 1] == ' ')
    {
      show_error(tab, i + 2, pos, "Number expected");
      return (-1);
    }
}

int     label_char_err(char *tab, int pos, int i)
{
  if (tab[i] == ':' && tab[i + 1] == ' ')
    {
      show_error(tab, i + 2, pos, "Label expected");
      return (-1);
    }
  if (tab[0] == ':')
    {
      show_error(tab, i, pos, "Unknown mnémonique");
      return (-1);
    }
}

int	count_octet_param(char *param)
{
  int	oct;

  oct = 0;
  if (param[0] == 'r')
    oct = T_REG;
  else if (param[0] == '%')
    oct = DIR_SIZE;
  else if (param[0] >= '0' && param[0] <= '9')
    oct = IND_SIZE;
  return (oct);
}

int     show_error(char *str, int pos, char *msg)
{
  int   cmp;
  int	j;

  my_printf("Error at line #%d : '%s' %s\n", pos, str, msg);
  exit(1);
}
