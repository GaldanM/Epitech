/*
** my_find_prime_sup.c for my_find_prime_sup in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct 17 12:51:02 2013 moulin_c
** Last update Thu Oct 17 13:00:30 2013 moulin_c
*/

int	my_find_prime_sup(int nb)
{
  int   i;

  if (nb == 1 || nb == 0)
    return (nb = 2);
  i = 2;
  while (i != nb)
    {
      if (nb % i == 0)
        {
	  nb = nb + 1;
        }
      i = i + 1;
    }
  return (nb);
}
