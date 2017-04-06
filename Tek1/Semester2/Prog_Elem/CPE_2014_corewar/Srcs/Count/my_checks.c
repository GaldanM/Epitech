/*
** my_checks.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 22:41:55 2014 moulin_c
** Last update Sun Apr 13 22:42:05 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/op.h"

# define IS_CHAR (str[i] < 'a' || str[i] > 'z')
# define IS_NUMBERS (str[i] < '0' || str[i] > '9')
# define IS_VAR_CHARS (str[i] != '_' && str[i] != '%' && str[i] != ':')

int	check_tab(char *tab, int pos)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      if (tab[i] == ':')
	{
	  if (label_char_err(tab, pos, i) == -1)
	    return (-1);
	}
      else if (tab[i] == '%')
	{
	  if (direct_char_err(tab, pos, i) == -1)
	    return (-1);
	}
      i++;
    }
}

int	check_error(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (check_string(tab[i], i) == -1)
      	return (-1);
      if (check_tab(tab[i], i) == -1)
	return (-1);
      i++;
    }
}

int	check_string(char *str, int pos)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (IS_CHAR && str[i] != ' ' && IS_VAR_CHARS && IS_NUMBERS)
	{
	  show_error(str, i + 1, pos, "Forbidden character");
	  return (-1);
	}
      i++;
    }
  return (0);
}
