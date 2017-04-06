/*
** my_strlen.c for my_strlen in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 19:53:33 2013 moulin_c
** Last update Fri Oct  4 20:02:03 2013 moulin_c
*/

int      my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      a = a + 1;
    }
  return(a);
}
