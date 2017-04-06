/*
** main.c for chiffres in /home/sement_s/rendu/colle4_moulin_c_S4gR1
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May 19 19:22:03 2014 Stephen SEMENT
** Last update Mon May 19 21:26:09 2014 Stephen SEMENT
*/

#include	<stdlib.h>

static int	*init_tab_nb(int ac, char **av)
{
  int		*tab_nb;
  int		i;

  i = 0;
  if ((tab_nb = malloc(sizeof(int) * (ac - 2))) == NULL)
    my_exitstr("Malloc error, program must close.\n", -1);
  while (i < ac - 2)
    {
      tab_nb[i] = my_atoi(av[i + 2]);
      i = i + 1;
    }
  find_ops(my_atoi(av[1]), tab_nb, ac - 3);
  return (0);
}

int		main(int ac, char **av)
{
  if (ac < 3)
    my_exitstr("Please refer to the README before using the program.\n", -1);
  else
    init_tab_nb(ac, av);
  exit(EXIT_SUCCESS);
}
