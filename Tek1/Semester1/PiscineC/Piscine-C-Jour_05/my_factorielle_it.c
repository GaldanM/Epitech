/*
** my_factorielle_it.c for my_factorielle_it in /home/moulin_c/rendu/Piscine-C-Jour_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 15:42:28 2013 moulin_c
** Last update Mon Oct  7 10:35:13 2013 moulin_c
*/

int	my_factorielle_it(int nb)
{
  int	c;
 
  c = 1;
  if (nb < 0 || nb > 13)
    {
      my_putchar('0');
    }
  else if (nb == 0)
    {
      my_putchar('1');
    }
  else
   {
     while (nb != 0)
       {
         c = c * nb;
         nb = nb - 1;
       }
     return (c);
   }
}
