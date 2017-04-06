/*
** my_getnbr.c for my_getnbr in /home/moulin_c/rendu/Piscine-C-Jour_04
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Oct  4 10:05:59 2013 moulin_c
** Last update Fri Oct  4 20:05:57 2013 moulin_c
*/

int      my_getnbr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {   
      if (a < 48 || str[a] > 57 || a == 45 || a == 43)
	{
	  my_putchar(str[a]);
	  a = a + 1;
	}
      else 
	{
	  a = a + 1;
	}
    }
}
