/*
** do-op.c for do-op in /home/moulin_c/rendu/Piscine-C-Jour_11/do-op
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct 21 13:36:49 2013 moulin_c
** Last update Tue Oct 22 11:15:30 2013 moulin_c
*/

#include "operations.h"

int	check_argc(int nb)
{
  if (nb != 4)
    return (1);
  else
    return (0);
}

int     check_minus(char *argv2)
{
  int   a;
  int   b;
  int   sign;

  a = 0;
  b = 0;
  sign = 1;
  if (argv2[0] == '+' || argv2[0] == '-')
    while (argv2[a] != '\0')
      {
	if (argv2[a] == '-')
	  b = b + 1;
	a = a + 1;
      }
  if (b % 2 == 0)
    sign = -1;
  return (sign);
}

int	do_op(char *arg1, char *arg2, char *arg3)
{
  int   sign;
  int (*do_op[5])(char *, char *);

  if (arg2[0] == '+' || arg2[0] == '-')
    sign = check_minus(arg2);
  else
    sign = 0;
  do_op[0] = &add;
  do_op[1] = &sub;
  do_op[2] = &divide;
  do_op[3] = &multiple;
  do_op[4] = &modulo;

  if (sign == -1)
    do_op[0](arg1, arg3);
  else if (sign == 1)
    do_op[1](arg1, arg3);
  else if (arg2[0] == '/')
    do_op[2](arg1, arg3);
  else if (arg2[0] == '*')
    do_op[3](arg1, arg3);
  else if (arg2[0] == '%')
    do_op[4](arg1, arg3);
  else
    my_putstr("0\n");
}

int	main(int argc, char **argv)
{
  int	nc;

  nc = check_argc(argc);
  if (nc == 0)
    {
      do_op(argv[1], argv[2], argv[3]);
    }
  else
    return (0);
}
