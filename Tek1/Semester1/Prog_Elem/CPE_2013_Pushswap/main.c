/*
** main.c for pushswap in /home/moulin_c/mbin
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan  6 16:48:14 2014 moulin_c
** Last update Mon Jan  6 17:39:09 2014 moulin_c
*/

#include "mylist.h"
#include "push.h"

int	check_flag(int i, char *flag, t_var *var)
{
  if (my_strcmp(flag, "-v") == 0)
    {
      var->va = 1;
      i++;
    }
  return (i);
}

int		main(int argc, char **argv)
{
  t_list	*list_a;
  t_list	*list_b;
  t_var		var;
  int		i;

  i = 1;
  var.key = 0;
  var.check = 0;
  var.va = 0;
  if (argc == 1)
    return (0);
  i = check_flag(i, argv[1], &var);
  list_a = make_list_circ();
  list_b = make_list_circ();
  while (argv[i])
    add_elem_circ_end(&list_a, my_getnbr(argv[i++]));
  while ((var.check = check_sort_list(&list_a, &list_b, &var)) == 0)
    {
      if (var.check == 0)
	my_rotate(&list_a, &list_b, &var);
    }
  if (!var.va)
    my_putchar('\n');
}
