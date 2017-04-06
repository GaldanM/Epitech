/*
** my_putstr_rev.c for str_rev in /home/moulin_c/rendu/Lib/Piscine-C-lib/my
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Nov 27 13:06:53 2013 moulin_c
** Last update Wed Nov 27 13:07:13 2013 moulin_c
*/

void	my_putstr_rev(char *str, int i)
{
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i - 1;
    }
}
