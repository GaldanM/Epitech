/*
** my_strstr.c for my_strstr in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 16:44:51 2013 moulin_c
** Last update Tue Oct  8 22:10:53 2013 moulin_c
*/

int	check(char *str, char *to_find)
{
  if (to_find[0] == '\0')
    return (1);
  else
    return (0);
  if (str[0] == '\0')
    return (2);
  else
    return (0);
}

char	*my_strstr(char *str, char *to_find)
{
  int	a;
  int	b;
  int	c;

  if (check(str, to_find) == 1)
    return (str);
  if (check(str, to_find) == 2)
    return (0);
  a = 0;
  b = 0;
  while (str[a] != '\0')
    {
      if (str[a] == to_find[b])
	{
	  c = a;
	  while (str[a] == to_find[b])
	    {
	      a = a + 1;
	      b = b + 1;
	      if (to_find[b] == '\0')
		  return (&str[c]);
	    }
	  b = 0;
	}
      a = a + 1;
    }
  return (0);
}
