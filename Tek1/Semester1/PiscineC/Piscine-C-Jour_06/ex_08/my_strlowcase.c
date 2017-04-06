/*
** my_strlowcase.c for my_strlowcase in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_08
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 15:51:16 2013 moulin_c
** Last update Tue Oct  8 20:15:30 2013 moulin_c
*/

char    *my_strlowcase(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= 65 && str[a] <= 90)
        {
          str[a] = str[a] + 32;
          a = a + 1;
        }
      else
        {
          a = a + 1;
        }
    }
  return (str);
}
