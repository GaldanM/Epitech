/*
** my_putstr_mod.c for my_putstr_mod in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 18:51:01 2013 moulin_c
** Last update Thu Oct 24 17:00:09 2013 moulin_c
*/

int	 my_putstr_mod(char *str, int ret)
{
  int	a;

  a = 0;
  while (ret != a)
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
