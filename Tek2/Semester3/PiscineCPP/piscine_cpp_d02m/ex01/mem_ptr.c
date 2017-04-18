/*
** mem_ptr.c for mem_ptr in /home/moulin_c/rendu/piscine_cpp_d02m
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 10:09:10 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 11:00:57 2015 Galdan MOULINNEUF
*/

#include	<stdlib.h>
#include	<string.h>
#include	"mem_ptr.h"

void		add_str(char *str1, char *str2, char **res)
{
  int		i = 0;
  int		j = 0;

  if (((*res) = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1))) == NULL)
    return;
  while (str1[j])
    (*res)[i++] = str1[j++];
  j = 0;
  while (str2[j])
    (*res)[i++] = str2[j++];
  (*res)[i] = 0;
}

void		add_str_struct(t_str_op *str_op)
{
  int		i = 0;
  int		j = 0;

  if ((str_op->res = malloc(sizeof(char) * strlen(str_op->str1) + strlen(str_op->str2) + 1)) == NULL)
    return;
  while (str_op->str1[j])
    {
      str_op->res[i] = str_op->str1[j];
      i++;
      j++;
    }
  j = 0;
  while (str_op->str2[j])
    {
      str_op->res[i] = str_op->str2[j];
      i++;
      j++;
    }
  str_op->res[i] = 0;
}
