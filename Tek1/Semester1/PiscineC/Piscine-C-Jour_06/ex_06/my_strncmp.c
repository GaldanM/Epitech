/*
** my_strncmp.c for my_strncmp in /home/moulin_c/rendu/Piscine-C-Jour_06
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 13:43:47 2013 moulin_c
** Last update Tue Oct  8 20:13:53 2013 moulin_c
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int   count;
  int   result;

  count = 0;
  count = count - 1;
  while (count != n || s1[count] != '\0'  || s2[count] != '\0')
    {
      if (s1[count] != s2[count] || count == n)
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
