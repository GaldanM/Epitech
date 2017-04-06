/*
** my_put_label_in_hexa.c for corewar in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Write
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 18:12:46 2014 moulin_c
** Last update Sun Apr 13 23:03:09 2014 moulin_c
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../Includes/asm.h"

void	if_direct(int ret, int i, char **tab, int fd)
{
  int	nb;

  nb = my_getnbr(tab[i] + 1);
  if (tab[i][1] == ':')
    {
      nb = my_getnbr(tab[i] + 2);
      putnbr_file(nb, 4, fd);
    }
  if (ret == 12 || ret == 9 || ret == 15 || ret == 11 || ret == 10)
    putnbr_file(nb, 2, fd);
  else
    {
      nb = my_getnbr(tab[i]);
      putnbr_file(nb, 4, fd);
    }
}

void	param_instr(char **tab, int fd, int ret)
{
  int	i;
  int	nb;

  i = 1;
  while (tab[i])
    {
      if (tab[i][0] == 'r')
	{
	  nb = my_getnbr(tab[i] + 1);
	  if (ret == 12 || ret == 9 || ret == 15)
	    putnbr_file(nb, 2, fd);
	  else
	    putnbr_file(nb, 1, fd);
	}
      else if (tab[i][0] == '%')
	if_direct(ret, i, tab, fd);
      else
	{
	  nb = my_getnbr(tab[i]);
	  putnbr_file(nb, 4, fd);
	}
      i++;
    }
}

void	check_nb_param(char **tab, int ret)
{
  if (ret == 1 || ret == 9 || ret == 12 || ret == 15)
    {
      if (tab[2])
	tab[2] = NULL;
    }
  else if (ret == 2 || ret == 3 || ret == 13)
    {
      if (tab[3])
	tab[3] = NULL;
    }
  else
    {
      if (tab[4])
	tab[4] = NULL;
    }
}

int	write_instr(char **tab, int fd)
{
  int	i;
  int	j;
  int	ret;

  i = 0;
  j = 0;
  ret = put_mnemo_in_file(tab[0], fd);
  check_nb_param(tab, ret);
  if (ret != 1 && ret != 9 && ret != 12 && ret != 15)
    octet_codage(tab, fd, ret);
  param_instr(tab, fd, ret);
}
