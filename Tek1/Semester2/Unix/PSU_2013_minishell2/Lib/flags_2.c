/*
** flags_2.c for printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Nov 15 17:53:41 2013 moulin_c
** Last update Fri Nov 22 11:05:21 2013 moulin_c
*/

#include "../Includes/flags.h"

void	if_u(va_list arg_pos, char *str, int i)
{
  my_putnbrbase(va_arg(arg_pos, unsigned int), "0123456789");
}

void	if_x(va_list arg_pos, char *str, int i)
{
  my_putnbrbase(va_arg(arg_pos, int), "0123456789abcdef");
}

void	if_bx(va_list arg_pos, char *str, int i)
{
  my_putnbrbase(va_arg(arg_pos, int), "0123456789ABCDEF");
}

void	if_o(va_list arg_pos, char *str, int i)
{
  my_putnbrbase(va_arg(arg_pos, int), "01234567");
}

void	if_p(va_list arg_pos, char *str, int i)
{
  void	*ptr;

  ptr = va_arg(arg_pos, void *);
  if (ptr == NULL)
    my_putstr("(nil)");
  else
    {
      my_putstr("0x");
      my_putnbrbase(ptr, "0123456789abcdef");
    }
}
