/*
** main.c for Bistro in /home/moulin_c/rendu/Modules/C_Prog_Elem/Bistro/operations
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Nov 10 16:04:02 2013 moulin_c
** Last update Sun Nov 10 16:32:14 2013 moulin_c
*/

#include "Bistromatique.h"

static void     check_base(char *base)
{
  if (my_strlen(base) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
}

static void     check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(5);
    }
}

static char     *get_expr(unsigned int size)
{
  char  *expr;

  if (size <= 0)
    {
      my_putstr("Bad expr lenght\n");
      exit(2);
    }
  expr = malloc(size + 1);
  if (expr == 0)
    {
      my_putstr("Bad Malloc\n");
      exit(3);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr("could not read\n");
      exit(4);
    }
  return (expr);
}

int             main(int ac, char **av)
{
  char          *expr;
  unsigned int  size;
  char  *final_res;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      exit(1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  final_res = (eval_expr(expr));
  my_putstr(final_res);
  free(final_res);
  return (0);
}
