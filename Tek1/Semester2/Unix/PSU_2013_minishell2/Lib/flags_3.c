/*
** flags_3.c for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 15 17:57:59 2013 moulin_c
** Last update Sat Nov 16 17:36:03 2013 moulin_c
*/

#include "../Includes/flags.h"

void	if_percent(va_list arg_pos, char *str, int i)
{
  my_putchar('%');
}

void	if_b(va_list arg_pos, char *str, int i)
{
  my_putnbrbase(va_arg(arg_pos, unsigned int), "01");
}

void	if_no(va_list arg_pos, char *str, int i)
{
  my_putchar('%');
  my_putchar(str[i]);
}

void	if_m(va_list arg_pos, char *str, int i)
{
  my_putstr("SUCCESS");
}
