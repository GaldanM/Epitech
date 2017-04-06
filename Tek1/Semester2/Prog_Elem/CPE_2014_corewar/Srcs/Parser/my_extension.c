/*
** my_extension.c for extensiooon in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 16:01:42 2014 moulin_c
** Last update Sun Apr 13 23:15:05 2014 moulin_c
*/

#include <stdlib.h>

int	my_extension(char *str)
{
  int	nb;

  nb = my_strlen(str);
  nb--;
  if (str[nb] == 's' && str[nb - 1] == '.' && str[nb - 2])
    return (0);
  else
    my_printf("Bad file '%s'\n", str);
  exit(1);
}
