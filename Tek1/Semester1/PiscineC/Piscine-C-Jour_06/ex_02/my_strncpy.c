/*
** my_strncpy.c for my_strncp in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_02
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 12:04:01 2013 moulin_c
** Last update Tue Oct  8 11:27:03 2013 moulin_c
*/

char    *my_strncpy(char *dest, char *src, int n)
{
   int   a;

  a = 0;
  while (a != n)
    {
      dest[a] = src[a];
      a = a + 1;
      if (src[a] == '\0')
	{
	  my_putchar('\0');
	  return (dest);
	}
    }
  return (dest);
}
