/*
** my_check_type.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 22:40:10 2014 moulin_c
** Last update Sun Apr 13 23:00:08 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/op.h"

char	*check_param(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (NULL);
  if (str[i] == 'r' || str[i] == '%')
    i++;
  if (str[0] == '%' && (str[1] == ':' || str[1] == '-'))
    i++;
  else
    while (str[i])
      {
	if (str[i] < '0' || str[i] > '9')
	  return (NULL);
	i++;
      }
  if (str[0] == '%' && str[1] == ':' && !str[2])
    return (NULL);
  if ((str[0] == 'r' || str[0] == '%') && !str[1])
    return (NULL);
  return (str);
}

int	var_len(char *str, int len)
{
  if (my_strlen(str) > len)
    return (-1);
  return (0);
}

int	is_overflow(char **tab, int pos, int i)
{
  int	bin;

  bin = 0;
  if (tab[i][0] == 'r')
    {
      if (my_getnbr(tab[i] + 1) > REG_NUMBER || my_getnbr(tab[i] + 1) <= 0)
	show_error(tab[i], pos, "no such register");
      bin = (1 << 0) | bin;
    }
  else if (tab[i][0] == '%')
    {
      if (tab[i][1] != ':')
	{
	  if (var_len(tab[i] + 1, 9) == -1)
	    my_printf("Warning Direct too big line %d\n", pos);
	}
      bin = (1 << 1) | bin;
    }
  else if (tab[i][0] >= '0' && tab[i][0] <= '9')
    {
      if (var_len(tab[i], 3) == -1 || my_getnbr(tab[i]) > IDX_MOD)
	my_printf("Warning Indirection too far line %d\n", pos);
      bin = (1 << 2) | bin;
    }
  return (bin);
}

int	is_bad_arg(char **tab, int pos, int i, int mnemo)
{
  int	bin;
  int	j;

  j = 0;
  while (tab[i])
    {
      bin = is_overflow(tab, pos, i);
      if (i != 1 && (op_tab[mnemo].nbr_args + 1) == i)
	return (0);
      if (check_param(tab[i]) == NULL)
	show_error(tab[i], pos, "is a bad argument");
      if (tab[i] && (!(bin & op_tab[mnemo].type[j])))
	show_error(tab[i], pos, "is a bad argument");
      j++;
      i++;
    }
}

int	check_type(char **tab, int pos)
{
  int	bin;
  int	cmp;
  int	i;
  int	k;
  int	mnemo;

  i = 0;
  cmp = 0;
  while ((op_tab[i].mnemonique) && tab[0] &&
	 (my_strcmp(tab[0], op_tab[i].mnemonique)))
    i++;
  if (!op_tab[i].mnemonique)
    show_error(op_tab[i].mnemonique, pos, "is unknown");
  mnemo = i;
  k = i;
  i = 1;
  is_bad_arg(tab, pos, i, mnemo);
  if (!tab[i] && (i < op_tab[mnemo].nbr_args + 1))
    show_error(tab[0], pos, "Not enough arguments");
}
