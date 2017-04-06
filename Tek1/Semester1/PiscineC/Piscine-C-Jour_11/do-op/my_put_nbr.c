/*
** my_put_nbr.c for my_put_nbr in /home/moulin_c/rendu/Piscine-C-Jour_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 10:56:17 2013 moulin_c
** Last update Fri Oct 11 14:18:40 2013 moulin_c
*/

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  if (nb == 0)
    my_putchar(48);
  else
    {
      calcul_putnbr(nb);
    }
}

int	calcul_putnbr(int nb)
{
  int	modulo;
  int	reste;
  int	result;

  modulo = 1;
  while (reste != nb)
    {
      modulo  = modulo * 10;
      reste = nb % modulo;
    }
  while (modulo != 1)
    {
      modulo = modulo / 10;
      result = nb / modulo;
      my_putchar(result + 48);
      nb = nb % modulo;
    }
}
