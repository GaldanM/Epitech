/*
** my_rev_params.c for my_rev_params in /home/moulin_c/rendu/Piscine-C-Jour_07/ex_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 21:37:34 2013 moulin_c
** Last update Wed Oct  9 21:44:30 2013 moulin_c
*/

int	main(int argc, char **argv)
{
  int	count;

  count = 0;
  while (count != argc)
    {
      count = count + 1;
    }
  while (count != 0)
    {
      count = count - 1;
      my_putstr(argv[count]);
      my_putchar('\n');
    }
}
