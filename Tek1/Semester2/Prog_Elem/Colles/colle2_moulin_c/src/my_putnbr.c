/*
** my_putnbr.c for mastermind in /home/moulin_c/rendu/colle2_moulin_c
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May  5 19:45:25 2014 moulin_c
** Last update Mon May  5 21:45:19 2014 moulin_c
*/

void	my_putnbr(int nb)
{
  int	mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  else if (nb == 0)
    my_putchar('0');
  else
    {
      mod = 1;
      while (nb % mod != nb)
	mod = mod * 10;
      mod = mod / 10;
      while (mod > 0)
	{
	  my_putchar((nb / mod) + 48);
	  nb = nb % mod;
	  mod = mod / 10;
	}
    }
}

