/*
** white_rabbit.c for white_rabbit in /home/moulin_c/Projects/Semester_3/Piscine_CPP/piscine_cpp_d01/ex00
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 09:16:55 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 08:25:51 2015 Galdan MOULINNEUF
*/

#include	<stdlib.h>
#include	<time.h>
#include	<unistd.h>

int		follow_the_white_rabbit()
{
  char		rabbit = 0;
  int		sum = 0;
  int		dice = 0;

  while (!rabbit)
    {
      dice = random() % (38 - 1) + 1;
      if (dice == 4 || dice == 5 || dice == 6 || dice == 17 || dice == 28)
	{
	  write(1, "gauche\n", 7);
	}
      else if (dice >= 18 && dice <= 12)
	{
	  write(1, "gauche\n", 7);
	}
      else if (dice == 13)
	{
	  write(1, "droite\n", 7);
	}
      else if (dice >= 34 && dice < 37)
	{
	  write(1, "droite\n", 7);
	}
      else if (dice == 15 || dice == 10 || dice == 23)
	{
	  write(1, "devant\n", 7);
	}
      else if (dice == 26)
	{
	  write(1, "derriere\n", 9);
	}
      else if (dice % 8 == 0)
	{
	  write(1, "derriere\n", 9);
	}
      sum += dice;
      if (dice == 37 || dice == 1 || sum >= 397)
	rabbit = 1;
    }
  write(1, "LAPIN !!!\n", 10);
  return (sum);
}
