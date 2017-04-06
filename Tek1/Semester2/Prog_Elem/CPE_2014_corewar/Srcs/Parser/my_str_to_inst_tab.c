/*
** my_str_to_inst_tab.c for ASM in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Mar 30 10:09:48 2014 moulin_c
** Last update Sun Apr 13 23:17:54 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/op.h"

#define	SPACES(car)		(car == ' ' || car == '\t' || car == SEPARATOR_CHAR)

int	count_words(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] && str[i] != COMMENT_CHAR)
    {
      while (str[i] && SPACES(str[i]) && str[i] != COMMENT_CHAR)
	i++;
      while (str[i] && !SPACES(str[i]) && str[i] != COMMENT_CHAR)
	i++;
      if (str[i] || nb > 0 || str[i] != COMMENT_CHAR)
	nb++;
    }
  return (nb);
}

/* void	my_show_tab(char **tab) */
/* { */
/*   int	i; */

/*   i = 0; */
/*   while (tab[i] != NULL) */
/*     { */
/*       printf("'%s'\t", tab[i]); */
/*       i++; */
/*     } */
/* } */

int	browse_str(char *str, int i, int *beg, int *end)
{
  while (str[i] && SPACES(str[i]) && str[i] != COMMENT_CHAR)
    i++;
  *beg = i;
  while (str[i] && !SPACES(str[i]) && str[i] != COMMENT_CHAR)
    i++;
  if (str[i] == COMMENT_CHAR)
    *end = i - 2;
  else
    *end = i - 1;
  return (i);
}

int	my_str_to_inst_tab(char *str, char **tab)
{
  int	beg;
  int	end;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  while (str[i] && str[i] != COMMENT_CHAR)
    {
      i = browse_str(str, i, &beg, &end);
      if ((tab[j] = malloc(sizeof(char) * (end - beg + 1))) == NULL)
	return (-1);
      k = 0;
      while (beg <= end)
	{
	  tab[j][k] = str[beg];
	  k++;
	  beg++;
	}
      tab[j][k] = '\0';
      j++;
    }
  tab[j] = NULL;
}
