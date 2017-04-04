/*
** my_strncpy.c for my_strncp in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_02
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 12:04:01 2013 moulin_c
** Last update Fri Oct 11 17:25:44 2013 moulin_c
*/

char    *my_strncpy(char *dest, char *src, int nb)
{
   int   a;

  a = 0;
  while (a != nb)
    {
      my_putchar(src[a]);
      dest[a] = src[a];
      a = a + 1;
      if (src[a] == '\0')
	{
	  dest[a] = '\0';
	  return (dest);
	}
    }
  return (dest);
}
