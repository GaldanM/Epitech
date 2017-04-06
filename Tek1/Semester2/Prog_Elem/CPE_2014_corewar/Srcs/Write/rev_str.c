/*
** rev_str.c for asm in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Corewar/ASM/Write
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Apr 13 17:18:07 2014 moulin_c
** Last update Sun Apr 13 17:18:08 2014 moulin_c
*/

#include <stdlib.h>

char	*rev_str(char *str)
{
  int   i;
  int   j;
  char  *new;

  j = my_strlen(str) - 1;
  i = 0;
  if ((new = malloc(my_strlen(str) * sizeof(char))) == NULL)
    exit(1);
  while (j >= 0)
    {
      new[i] = str[j];
      i++;
      j--;
    }
  new[i] = '\0';
  return (new);
}
