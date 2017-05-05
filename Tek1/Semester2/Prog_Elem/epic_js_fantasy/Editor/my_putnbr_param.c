/*
** tt.c for  in /home/medec_o/rendu/corewar/str_to_inst_tab/test
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Thu Apr  3 16:15:02 2014 medec_o
** Last update Sun May 11 21:17:38 2014 moulin_c
*/

#include <unistd.h>
#include "editor.h"

int		my_putnbr_param(int nb, int oct, int fd)
{
  int		i;
  t_file	t;

  i = 0;
  t.p.bin = 0;
  while (i <= 32)
    {
      t.p.nbr[i] = 0;
      if ((((1 << i) & nb)) > 0)
	{
	  t.p.bin = (1 << i) | nb;
	  i++;
	}
      else
	i++;
    }
  t.p.nbr[i] = '\0';
  my_putstr_file(t.p.nbr, fd, oct);
  return (fd);
}
