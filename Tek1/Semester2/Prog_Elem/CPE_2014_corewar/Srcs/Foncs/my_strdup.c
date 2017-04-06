/*
** my_strdup.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Foncs
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 23:08:32 2014 moulin_c
** Last update Sun Apr 13 23:08:34 2014 moulin_c
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	lenght;
  char	*str_new;

  lenght = my_strlen(src);
  if ((str_new = malloc(sizeof(char) * (lenght + 1))) == NULL)
    exit(1);
  lenght = 0;
  while (src[lenght])
    str_new[lenght] = src[lenght++];
  str_new[lenght] = '\0';
  return (str_new);
}
