/*
** my_strncat.c for my_strncat in /home/moulin_c/rendu/Piscine-C-Jour_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  9 15:53:55 2013 moulin_c
** Last update Wed Oct  9 20:46:37 2013 moulin_c
*/

char     *my_strncat(char *dest, char *src, int nb)
{
  int   a;
  int   b;

  a = 0;
  b = 0;
  while (dest[a] != '\0')
    {
      a = a + 1;
    }
  while (b != nb)
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
