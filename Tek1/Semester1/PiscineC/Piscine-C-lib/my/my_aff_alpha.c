/*
** my_aff_alpha.c for my_aff_alpha in /home/moulin_c/rendu/Piscine-C-Jour_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  2 09:32:31 2013 moulin_c
** Last update Thu Oct  3 20:50:52 2013 moulin_c
*/

int	my_aff_alpha()
{
  char	begin;
	
  begin = 97;
  while (begin < 123)
    {
      my_putchar(begin);
      begin = begin + 1;
    }
}
