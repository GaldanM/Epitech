/*
** printf.c for Printf in /home/moulin_c/rendu/tests/printf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Nov 11 13:54:21 2013 moulin_c
** Last update Fri Nov 22 11:05:20 2013 moulin_c
*/

#include "flags.h"

int		my_printf(char *str, ...)
{
  va_list	arg_pos;
  int		i;

  i = 0;
  va_start(arg_pos, str);
  while (str[i] != '\0')
   {
      if (str[i] == '%')
	{
	  i = i + 1;
	  while (str[i] == ' ' || str[i] == '-')
	    i = i + 1;
	  if (str[i] == '\0')
	    return (0);
	  tab_flag(arg_pos, str, i);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
  va_end(arg_pos);
}
