/*
** my_strlcat.c for my_strlcat in /home/moulin_c/rendu/Piscine-C-Jour_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 18:38:49 2013 moulin_c
** Last update Wed Oct  9 20:46:30 2013 moulin_c
*/

char     *my_strlcat(char *dest, char *src, int size)
{
  int   a;
  int   b;

  a = 0;
  b = 0;
  while (dest[a] != '\0')
    {
      a = a + 1;
    }
  while (a < size - 1)
    {
      if (src[b] == '\0')
        {
	  dest[a] = ('\0');
          return (dest);
        }
      dest[a] = src[b];
      a = a + 1;
      b = b + 1;
    }
  dest[a] = ('\0');
  return (dest);
}
