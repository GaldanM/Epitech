/*
** my_strcpy.c for my_strcpy in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 09:33:28 2013 moulin_c
** Last update Fri Oct 11 16:26:57 2013 moulin_c
*/

char    *my_strcpy(char *dest, char *src)
{
  int	a;

  a = 0;
  while (src[a] != '\0')
    {
      dest[a] = src[a];
      a = a + 1;
    }
  return (dest);
}
