/*
** ex_6.h for foo foo foo in /home/moulin_c/rendu/piscine_cpp_d01/ex06
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  7 20:51:21 2015 Galdan MOULINNEUF
** Last update Wed Jan  7 21:42:34 2015 Galdan MOULINNEUF
*/

#ifndef EX_6_H_
# define EX_6_H_

typedef union	s_first
{
  unsigned short	bar;
  unsigned short	foo;
}		t_first;

typedef struct	s_second
{
  unsigned short	foo;
  union s_first		bar;
}		t_second;

typedef union	s_foo
{
  unsigned int		bar;
  struct s_second	foo;
}		t_foo;

# endif /* EX_6_H_ */
