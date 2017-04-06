0/*
** my_str_isupper.c for my_str_isupper in /home/moulin_c/rendu/Piscine-C-Jour_06/ex_13
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Oct  8 21:30:38 2013 moulin_c
** Last update Tue Oct  8 22:18:47 2013 moulin_c
*/

int     my_str_isupper(char *str)
{
  int   count;

  count = 0;
  while (str[count] != '\0')
    {
      if (str[count] < 65 || str[count] > 90)
       	  return (0);
      count = count + 1;
    }
  return (1);
}
