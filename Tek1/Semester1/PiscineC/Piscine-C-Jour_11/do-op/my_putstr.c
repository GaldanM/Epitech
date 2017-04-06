/*
** my_putstr.c for my_putstr in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 18:51:01 2013 moulin_c
** Last update Fri Oct  4 20:02:34 2013 moulin_c
*/

int	 my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
