/*
** my_strupcase.c for my_strupcase in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_07
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 15:49:53 2013 moulin_c
** Last update Tue Oct  8 20:14:45 2013 moulin_c
*/

char    *my_strupcase(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] >= 97 && str[a] <= 122)
        {
         str[a] = str[a] - 32;
          a = a + 1;
        }
      else
        {
          a = a + 1;
        }
    }
  return (str);
}
