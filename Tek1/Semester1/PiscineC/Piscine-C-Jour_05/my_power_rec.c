/*
** my_power_rec.c for my_power_rec in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun Oct  6 13:30:51 2013 moulin_c
** Last update Mon Oct  7 08:37:05 2013 moulin_c
*/

int	my_power_rec(int nb, int power)
{
  int   a;
  int   c;

  a = 0;
  nb = check(nb);
  c = nb;
  if (power == 0 || power < 0)
    {
      my_putchar('1');
    }
  else
    {
      nb = calcul(power, a, nb, c);
      my_putchar(nb);
    }
}

int     calcul(int power, int a, int nb, int c)
{
  if (a == power - 1)
    {
      return (nb);
    }
  nb = c * nb;
  a = a + 1;
  calcul(power, a, nb, c);
}

int     check(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1 ;
    }
  else if (nb == 0)
    {
      my_putchar ('0');
    }
  return (nb);
}

