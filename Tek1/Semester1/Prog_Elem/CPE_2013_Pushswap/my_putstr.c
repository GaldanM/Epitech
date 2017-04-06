/*
** my_putstr.c for my_putstr in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 18:51:01 2013 moulin_c
** Last update Fri Dec 27 12:22:59 2013 moulin_c
*/

void	 my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
}
