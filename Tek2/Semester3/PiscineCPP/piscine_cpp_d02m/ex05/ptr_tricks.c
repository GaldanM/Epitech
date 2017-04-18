/*
** ptr_tricks.c for ptr_tricks in /home/moulin_c/rendu/piscine_cpp_d02m/ex05
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan  8 18:14:32 2015 Galdan MOULINNEUF
** Last update Thu Jan  8 18:18:27 2015 Galdan MOULINNEUF
*/

#include	"ptr_tricks.h"

int		get_array_nb_elem(int *ptr1, int *ptr2)
{
  int	i = 0;

  while (ptr1 != ptr2 && ptr1 > ptr2)
    {
      i++;
      ptr1--;
    }
  while (ptr1 != ptr2 && ptr1 < ptr2)
    {
      i++;
      ptr1++;
    }
  return (i);
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  t_whatever	smthng;
  int		length;

  length = get_array_nb_elem((int*)&smthng, &(smthng.member));
  return ((t_whatever *)(member_ptr - length));
}

