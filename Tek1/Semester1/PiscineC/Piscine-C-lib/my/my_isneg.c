/*
** my_isneg.c for my_isneg in /home/moulin_c/rendu/A check
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct 11 13:58:33 2013 moulin_c
** Last update Fri Oct 11 14:01:59 2013 moulin_c
*/

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else if (n >= 0)
    my_putchar('P');
  else
    return (0);
}
