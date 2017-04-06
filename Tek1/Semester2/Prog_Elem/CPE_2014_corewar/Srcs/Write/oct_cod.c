/*
** oct_cod.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 22:43:15 2014 moulin_c
** Last update Sun Apr 13 22:44:49 2014 moulin_c
*/

#include "../Includes/asm.h"

int	get_bin_nbr(char *bin)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  bin = rev_str(bin);
  while (bin[i])
    {
      if (bin[i] == '1')
	nb = (1 << i) | nb;
      i++;
    }
  return (nb);
}

void	octet_codage(char **tab, int fd, int ret)
{
  int	i;
  int	j;
  char	bin[10];
  int	nb;

  i = 1;
  j = 0;
  bin[0] = '\0';
  while (tab[i])
    {
      if (tab[i][0] == 'r')
	my_strcat(bin, "01");
      else if (tab[i][0] == '%')
	my_strcat(bin, "10");
      else
	my_strcat(bin, "11");
      i++;
    }
  if (ret == 2 || ret == 3 || ret == 13)
    my_strcat(bin, "00");
  else if (ret == 1 || ret == 9 || ret == 12 || ret == 15)
    my_strcat(bin, "0000");
  my_strcat(bin, "00");
  nb = get_bin_nbr(bin);
  putnbr_file(nb, 1, fd);
}
