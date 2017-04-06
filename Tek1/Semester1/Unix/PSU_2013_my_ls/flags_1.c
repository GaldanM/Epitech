/*
** flags_1.c for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 15 16:10:44 2013 moulin_c
** Last update Sat Nov 16 18:27:18 2013 moulin_c
*/

#include "flags.h"

void	if_d(va_list arg_pos, char *str, int i)
{
  my_put_nbr(va_arg(arg_pos, int));
}

void	if_i(va_list arg_pos, char *str, int i)
{
  if_d(arg_pos, str, i);
}

void	if_s(va_list arg_pos, char *str, int i)
{
  my_putstr(va_arg(arg_pos, char *));
}

void	if_bs(va_list arg_pos, char *str, int i)
{
  my_putstr_s(va_arg(arg_pos, char *));
}

void	if_c(va_list arg_pos, char *str, int i)
{
  my_putchar(va_arg(arg_pos, int));
}
