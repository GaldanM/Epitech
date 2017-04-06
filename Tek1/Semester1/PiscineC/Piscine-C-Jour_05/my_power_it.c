/*
** my_power_it.c for my_power_it in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Oct  5 20:10:35 2013 moulin_c
** Last update Mon Oct  7 20:25:55 2013 moulin_c
*/

int     my_power_it(int nb, int power)
{
  int	a;
  int	c;

  a = 0;
  check(nb);
  c = nb; 
  if (power == 0 || power < 0)
    {
      my_putchar('1');
    }
  else 
    {
      nb = calcul(power, a, nb, c);
      return (nb);
    }
}

int	calcul(int power, int a, int nb, int c)
{ 
 while (a != power - 1)
    {
      nb = c * nb;
      a = a + 1;
    }
  return (nb);
}

int	check(int nb)
{
  if (nb < 0)
    {
      nb = nb * - 1;
    }
  else if (nb == 0)
    {
      my_putchar ('0');
    }
  return (nb);
}
