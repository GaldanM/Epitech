/*
** my_revstr.c for my_revstr in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Oct  7 14:52:55 2013 moulin_c
** Last update Fri Oct 11 18:40:01 2013 moulin_c
*/

char	*my_revstr(char *str)
{
  int	count;
  int	numb;

  numb = my_strlen(str);
  count = 0;
  numb = numb - 1;
  while (count <= numb)
    {
      my_swap(&str[numb], &str[count]);
      count = count + 1;
      numb = numb - 1;
    }
  return (str);
}
