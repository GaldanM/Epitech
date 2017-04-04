/*
** my_factorielle_rec.c for my_factorielle_rec in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 21:07:01 2013 moulin_c
** Last update Mon Oct  7 15:12:32 2013 moulin_c
*/

int	display(int nb)
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
      result = rec(nb, result);
      return (result);
    }
}

int	rec(int nb, int result)
{
  if (nb == 0)
    {
      return (result);
    }
  else
    {
      result = result * nb;
      nb = nb - 1;
      rec(nb, result);
    }
}

int	my_factorielle_rec(int nb)
{
  int	result;

  result = display(nb);
  return (result);
}
