/*
** ls_mod_date.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  1 11:51:22 2013 moulin_c
** Last update Sun Dec  1 11:55:59 2013 moulin_c
*/

#include "my_ls.h"

char	*mod_date(char *date)
{
  int	i;
  int	j;
  char	*new_date;

  new_date = malloc(15 * sizeof(char));
  i = 4;
  j = 0;
  while (i != 16)
    new_date[j++] = date[i++];
  new_date[j] = '\0';
  return (new_date);
}
