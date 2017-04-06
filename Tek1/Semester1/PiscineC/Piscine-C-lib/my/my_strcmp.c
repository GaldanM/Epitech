/*
** my_strcmp.c for my_strcmp in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 10:14:57 2013 moulin_c
** Last update Tue Oct  8 12:41:54 2013 moulin_c
*/

int     my_strcmp(char *s1, char *s2)
{
  int   count;
  int   result;

  count = 0;
  while (s1[count] != '\0' || s2[count] != '\0')
    {
      if (s1[count] != s2[count])
        {
          result = s1[count] - s2[count];
          return (result);
        }
      else
        {
          count = count + 1;
        }
    }
}
