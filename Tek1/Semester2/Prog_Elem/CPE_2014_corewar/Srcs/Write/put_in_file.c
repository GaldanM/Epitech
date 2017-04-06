/*
** put_in_file.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Write
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 20:04:17 2014 moulin_c
** Last update Sun Apr 13 22:45:54 2014 moulin_c
*/

#include "../Includes/write.h"
#include "../Includes/op.h"

void		write_file(int d, int fd)
{
  write(fd, &d, 1);
}

int		putstr_file(char *str, int fd, int octet)
{
  int		i;

  i = octet - 1;
  while (i >= 0)
    {
      write_file(str[i], fd);
      i--;
    }
}

int		put_mnemo_in_file(char *str, int fd)
{
  int		i;

  i = 0;
  while (str && op_tab[i].mnemonique && (my_strcmp(str, op_tab[i].mnemonique)))
    i++;
  write_file(op_tab[i].code, fd);
  return (op_tab[i].code);
}

int		putnbr_file(int nb, int octet, int fd)
{
  int		i;
  union	u_int	bit;

  i = 0;
  bit.bin = 0;
  while (i <= 32)
    {
      bit.nbr[i] = 0;
      if ((((1 << i) & nb)) > 0)
	{
	  bit.bin = (1 << i) | nb;
	  i++;
	}
      else
	i++;
    }
  bit.nbr[i] = '\0';
  putstr_file(bit.nbr, fd, octet);
  return (fd);
}
