/*
** func_ptr.c for func_ptr in /home/moulin_c/rendu/piscine_cpp_d02m/ex03
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
* 
** Started on  Thu Jan  8 12:17:08 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 19:23:52 2015 Galdan MOULINNEUF
*/

#include	<string.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"func_ptr.h"

void		print_normal(char *str)
{
  printf("%s\n", str);
}

void		print_reverse(char *str)
{
  int		i;

  i = strlen(str) - 1;
  while (i >= 0)
    {
      printf("%c", str[i]);
      i--;
    }
  printf("\n");
}

void		print_upper(char *str)
{
  int		i = 0;

  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	printf("%c", str[i] - 32);
      else
	printf("%c", str[i]);
      i++;
    }
  printf("\n");
}

void		print_42(char *str)
{
  int		i = 0;

  while (str[i])
    i++;
  print_normal("42");
}

void		do_action(t_action action, char *str)
{
  void		(*funcs[4])();

  funcs[PRINT_NORMAL] = &print_normal;
  funcs[PRINT_REVERSE] = &print_reverse;
  funcs[PRINT_UPPER] = &print_upper;
  funcs[PRINT_42] = &print_42;
  (*funcs[action])(str);
}
