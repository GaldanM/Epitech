/*
** my_aff_chiffre.c for my_aff_chiffre in /home/moulin_c/rendu/Piscine-C-Jour_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  2 10:39:32 2013 moulin_c
** Last update Thu Oct  3 20:37:49 2013 moulin_c
*/

int     my_aff_chiffre()
{
  int	begin;

  begin = 48;
  while (begin < 58 )
    {
      my_putchar(begin);
      begin = begin + 1;
    }
}
