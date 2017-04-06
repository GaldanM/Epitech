/*
** my_revstr.c for my_revstr in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 14:52:55 2013 moulin_c
** Last update Tue Oct  8 11:27:35 2013 moulin_c
*/

int     my_swap(char *a, char *b)
{
  int   stock;

  stock = *a;
  *a = *b;
  *b = stock;
}

int      my_strlen(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      a = a + 1;
    }
  a = a - 1;
  return (a);
}

char	*my_revstr(char *str)
{
  int	count;
  int	numb;

  numb = my_strlen(str);
  count = 0;
  while (count <= numb)
    {
      my_swap(&str[numb], &str[count]);
      count = count + 1;
      numb = numb - 1;
    }
  return (str);
}
