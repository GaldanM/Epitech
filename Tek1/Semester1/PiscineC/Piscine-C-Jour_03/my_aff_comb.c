/*
** my_aff_comb.c for my_aff_comb in /home/moulin_c/rendu/Piscine-C-Jour_03
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Oct  2 13:57:48 2013 moulin_c
** Last update Thu Oct  3 20:38:10 2013 moulin_c
*/

int     disp_comb(char hundreds, char tens, char units)
{
  my_putchar(hundreds);
  my_putchar(tens);
  my_putchar(units);

  if (hundreds < 55)
    {
      my_putchar(44);
      my_putchar(32);
    }
}

int	my_aff_comb()
{
  char	hundreds;
  char	tens;
  char	units;

  hundreds = 48;
  tens = 49;
  units = 50;
  while (hundreds < 57)
    {
      while (tens < 57)
	{
	  while (units <= 57)
	    {
	      disp_comb(hundreds, tens, units);
	      units = units + 1;
	    }
	  tens = tens + 1;
	  units = tens + 1;
	}
      hundreds = hundreds + 1;
      tens = hundreds + 1;
      units = tens + 1;
    }
}
