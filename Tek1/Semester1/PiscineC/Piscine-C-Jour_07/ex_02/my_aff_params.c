/*
** my_aff_params.c for my_aff_params in /home/moulin_c/rendu/Piscine-C-Jour_07/ex_02
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 20:50:05 2013 moulin_c
** Last update Wed Oct  9 21:36:54 2013 moulin_c
*/

int	main(int argc, char **argv)
{
  int	count;

  count = 0;
  while (count != argc)
    {
      my_putstr(argv[count]);
      my_putchar('\n');
      count = count + 1;
    }
}
