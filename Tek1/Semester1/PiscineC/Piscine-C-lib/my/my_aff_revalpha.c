/*
** my_aff_revalpha.c for my_aff_revalpha in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  2 10:33:16 2013 moulin_c
** Last update Thu Oct  3 20:53:31 2013 moulin_c
*/

int     my_aff_revalpha()
{
  char	revbegin;

  revbegin = 12;
  while (revbegin > 96)
    {
      my_putchar(revbegin);
      revbegin = revbegin - 1;
    }
}
