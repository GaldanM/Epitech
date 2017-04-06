/*
** my_power_rec.c for my_power_rec in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Oct  6 13:30:51 2013 moulin_c
** Last update Fri Oct 11 15:51:23 2013 moulin_c
*/

int	my_power_rec(int nb, int power)
{
  int   a;
  int   c;

  a = 0;
  nb = check_power_rec(nb);
  c = nb;
  if (power == 0 || power < 0)
    return (nb = 1);
  else
    nb = calcul_power_rec(power, a, nb, c);
  }

int     calcul_power_rec(int power, int a, int nb, int c)
{
  if (a == power - 1)
    return (nb);
  nb = c * nb;
  a = a + 1;
  calcul_power_rec(power, a, nb, c);
}

int     check_power_rec(int nb)
{
  if (nb < 0)
    nb = nb * - 1;
  return (nb);
}
