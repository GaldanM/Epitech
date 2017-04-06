/*
** my.h for my.h in /home/sement_s/rendu/colle2_moulin_c/src
** 
** Made by Stephen SEMENT
** Login   <sement_s@epitech.net>
** 
** Started on  Mon May  5 19:45:18 2014 Stephen SEMENT
** Last update Mon May  5 22:42:21 2014 moulin_c
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_param
{
  char		*pions;
  char		*code;
  char		buffer[4096];
  int		try;
  int		slot;
  int		ret;
  int		key;
  int		win;
  int		check;
  int		good;
  int		bad;
}		t_param;

#endif /* !MY_H_ */
