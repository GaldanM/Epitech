/*
** my_power_it.c for my_power_it in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Oct  5 20:10:35 2013 moulin_c
** Last update Fri Oct 11 15:50:32 2013 moulin_c
*/

int     my_power_it(int nb, int power)
{
  int	a;
  int	c;

  a = 0;
  nb = check_power_it(nb);
  c = nb; 
  if (power == 0 || power < 0)
    return (nb = 1);
  else
    {
      nb = calcul_power_it(power, a, nb, c);
      return (nb);
    }
}

int	calcul_power_it(int power, int a, int nb, int c)
{ 
 while (a != power - 1)
    {
      nb = c * nb;
      a = a + 1;
    }
  return (nb);
}

int	check_power_it(int nb)
{
  if (nb < 0)
    nb = nb * - 1;
  return (nb);
}
