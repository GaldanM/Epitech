/*
** my_getstr.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 23:29:57 2014 moulin_c
** Last update Sun Apr 13 23:29:59 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/asm.h"

int	nbr_size(int nbr)
{
  int	size;

  size = 0;
  while (nbr > 0)
    {
      size++;
      nbr = nbr / 10;
    }
  return (size + 3);
}

char	*my_malloc_nbr(int size)
{
  char	*n_str;

  if ((n_str = malloc(size * sizeof(char))) == NULL)
    {
      write(2, "In my_malloc_nbr function malloc failed\n", 40);
      return (NULL);
    }
  return (n_str);
}

char	*my_concat_str(char *nb, int size, int flag)
{
  char	*n_str;

  if ((n_str = my_malloc_nbr(size)) == NULL)
    return (NULL);
  n_str[0] = '%';
  n_str[1] = ':';
  n_str[2] = '\0';
  if (flag == 1)
    {
      n_str[2] = '-';
      n_str[3] = '\0';
    }
  my_strcat(n_str, nb);
  return (n_str);
}

char	*my_getstr(int nbr)
{
  char	*nb;
  int	i;
  int	size;
  int	flag;

  i = 0;
  flag = 0;
  if ((nb = my_malloc_nbr((size = nbr_size(nbr)))) == NULL)
    return (NULL);
  if (nbr < 0)
    {
      flag = 1;
      nbr = nbr * (-1);
    }
  while (nbr > 0)
    {
      nb[i] = (nbr % 10) + 48;
      nbr = nbr / 10;
      i++;
    }
  nb[i] = '\0';
  nb = rev_str(nb);
  nb = my_concat_str(nb, size, flag);
  return (nb);
}
