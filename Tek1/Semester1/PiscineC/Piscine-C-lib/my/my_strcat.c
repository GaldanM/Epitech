/*
** my_strcat.c for my_strcat in /home/moulin_c/rendu/Piscine-C-Jour_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 15:16:47 2013 moulin_c
** Last update Wed Oct  9 20:46:52 2013 moulin_c
*/

char	*my_strcat(char *dest, char *src)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (dest[a] != '\0')
    {
      a = a + 1;
    }
  while (src[b] != '\0')
    {
      dest[a] = src[b];
      a = a + 1;
      b = b + 1;
    }
  dest[a] = ('\0');
  return (dest);
}
