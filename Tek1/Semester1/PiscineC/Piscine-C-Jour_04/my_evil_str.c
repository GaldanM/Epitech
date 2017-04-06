/*
** my_evil_str.c for my_evil_str in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Oct  3 20:17:43 2013 moulin_c
** Last update Fri Oct  4 20:01:45 2013 moulin_c
*/

int     my_evil_str(char *str)
{
  int	k;
  int	g;
  int	a;

  a = 0;
  k = my_strlen(str);
  g = k; 
  while (k != g / 2)
    {
     my_swap(&str[a], &str[k]);     
     k = k - 1;
     a = a + 1;      
    }
  my_putstr(&str[a]);
}
