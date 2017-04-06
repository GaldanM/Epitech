/*
** my_ls_other.c for my_ls in /home/moulin_c/rendu/Modules/Unix/My_ls/PSU_2013_my_ls
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Dec  1 11:09:42 2013 moulin_c
** Last update Sun Dec  1 18:14:38 2013 moulin_c
*/

#include "my_ls.h"

void	my_ls_other(char *str, int i)
{
  my_printf("ls: option requires an argument -- '%c'\n", str[i]);
  exit (1);
}
