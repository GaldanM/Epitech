/*
** my_recup_name_monster.c for  in /home/di-mam_a/rendu/Rush 2/lib
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Sun May 11 03:42:40 2014 di-mam_a
** Last update Sun May 11 21:48:25 2014 moulin_c
*/

#include <stdio.h>
#include "editor.h"

char	*my_recup_name(int i, char *name, char *msg)
{
  int	flag;
  char	*type;

  flag = 1;
  while (flag == 1 || flag == 2)
    {
      if (flag != 2)
	if (i)
	  printf("%s %d :\n", msg, i);
	else
	  printf("%s :\n", msg);
      type = get_next_line(0);
      if (type[0])
	flag = 0;
      else
	{
	  flag = 2;
	  printf("You didn't put the right name ");
	  if (!i)
	    printf(" %s :\n", msg);
	  else
	    printf(" %s %d :\n", msg, i);
	}
    }
  return (type);
}
