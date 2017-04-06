/*
** my_factorielle_rec.c for my_factorielle_rec in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 21:07:01 2013 moulin_c
** Last update Fri Oct 11 15:52:34 2013 moulin_c
*/

int	display_fac_rec(int nb)
{
  int	result;

  result = 1;
  if (nb == 0)
    {
      result = 1;
      return (result);
    }
  else if (nb < 0 || nb > 13)
    {
      result = 0;
      return (result);
    }
  else
    {
      result = fac_rec(nb, result);
      return (result);
    }
}

int	fac_rec(int nb, int result)
{
  if (nb == 0)
    return (result);
  else
    {
      result = result * nb;
      nb = nb - 1;
      fac_rec(nb, result);
    }
}

int	my_factorielle_rec(int nb)
{
  int	result;

  result = display_fac_rec(nb);
  return (result);
}
