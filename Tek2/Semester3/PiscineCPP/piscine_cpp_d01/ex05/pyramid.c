/*
** pyramid.c for pyramid in /home/moulin_c/rendu/piscine_cpp_d01/ex05
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 13:41:37 2015 Galdan MOULINNEUF
** Last update Wed Jan  7 15:52:18 2015 Galdan MOULINNEUF
*/

int		browse_pyramid(int **map, int size, int lvl, int pos, int lenght)
{
  int		left;
  int		right;

  lenght = lenght + map[lvl][pos];
  lvl++;
  if (lvl < size)
    {
      left = browse_pyramid(map, size, lvl, pos, lenght);
      right = browse_pyramid(map, size, lvl, pos + 1, lenght);
      if (left < right)
	return (left);
      return (right);
    }
  return (lenght);
}

int		pyramid_path(int size, int **map)
{
  return (browse_pyramid(map, size, 0, 0, 0));
}
