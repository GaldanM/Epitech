/*
** my_square_root.c for my_square_root in /home/moulin_c/rendu/A check
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct 11 16:01:13 2013 moulin_c
** Last update Fri Oct 11 16:11:33 2013 moulin_c
*/

int	my_square_root(int nb)
{
  int	square;

  square = 0;
  while (square * square <=  nb)
    {
      if (square * square == nb)
	return (square);
      square = square + 1;
    }
  return (square = 0);
}
