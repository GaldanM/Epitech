/*
** read_key.c for alum in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Feb  6 14:19:16 2014 moulin_c
** Last update Mon Feb 10 13:51:49 2014 moulin_c
*/

#include "alum.h"

int	read_key(t_param *var, t_alum **tabl)
{
  char	buffer[100];

  if (read(0, buffer, 100) == - 1)
    return (-1);
  if (buffer[0] == ' ')
    gere_select(var, tabl);
  else if (buffer[0] == '\n')
    {
      gere_enter(var, tabl);
      return (1);
    }
  else if (buffer[0] == 's')
    gere_selectline(var, tabl);
  else if (buffer[0] == 'q')
    return (2);
  else if (buffer[0] == 27 && buffer[1] == 91)
    gere_arrows(buffer, var, tabl);
  return (0);
}
