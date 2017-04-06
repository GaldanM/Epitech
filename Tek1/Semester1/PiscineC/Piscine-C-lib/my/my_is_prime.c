/*
** my_is_prime.c for my_is_prime in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 17 12:23:31 2013 moulin_c
** Last update Thu Oct 17 13:00:45 2013 moulin_c
*/

int     my_is_prime(int nb)
{
  int	i;

  i = 2;
  while (i != nb)
    {
      if (nb % i == 0 || nb == 1)
	{
	  my_putchar('0');
	  return (nb = 0);
	}
      i = i + 1;
    }
  my_putchar('1');
  return (0);
}
