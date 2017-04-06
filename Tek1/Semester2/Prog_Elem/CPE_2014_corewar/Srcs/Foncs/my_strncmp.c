/*
** my_strncmp.c for my_strncmp in /home/moulin_c/rendu/Piscine-C-Jour_06
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 13:43:47 2013 moulin_c
** Last update Sun Apr 13 22:26:38 2014 moulin_c
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int   count;

  count = 0;
  while (count < n && s1[count] && s2[count])
    {
      if (s1[count] != s2[count])
	return (s1[count] - s2[count]);
      count++;
    }
  if (s1[count] != '\0')
    return (0);
  return (-1);
}
