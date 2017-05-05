/*
** my_verif_nbr.c for  in /home/di-mam_a/rendu/Rush 2/lib/recup_inst
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Sun May 11 03:55:11 2014 di-mam_a
** Last update Sun May 11 21:18:12 2014 moulin_c
*/

#include <stdio.h>
#include "editor.h"

void	aff_str(char *msg, char *name)
{
  if (name)
    printf("%s %s :\n", msg, name);
  else
    printf("%s :\n", msg);
}

int	my_verif_nbr(char *msg, int key, char *name)
{
  int	flag;
  int	nbr;
  char	*str;

  flag = 1;
  while (flag)
    {
      aff_str(msg, name);
      str = get_next_line(0);
      if (str[0])
	flag = 0;
      else
      	{
      	  flag = 2;
      	  printf("You didn't put the number of room!!\n");
      	}
      nbr = atoi(str);
      if (!nbr && !key)
      	{
      	  printf("You must have at least one room!!\n");
      	  flag = 2;
      	}
    }
  return (nbr);
}
