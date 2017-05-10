/*
** my_rev_params.c for my_rev_params in /home/moulin_c/rendu/Piscine-C-Jour_07/ex_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 21:37:34 2013 moulin_c
** Last update Fri Apr 18 02:02:29 2014 moulin_c
*/

int	main(int argc, char **argv)
{
  while (argc > 0)
    {
      argc--;
      my_putstr(argv[argc]);
      my_putchar('\n');
    }
  return (0);
}
