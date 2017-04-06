/*
** my.h for boogle in /home/moulin_c/rendu/colle6_moulin_c_7TtAi
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jun  2 19:12:42 2014 moulin_c
** Last update Mon Jun  2 20:40:21 2014 moulin_c
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_map
{
  char		letter;
  int		flag;
}		t_map;

typedef struct	s_param
{
  int		size;
  char		*grid;
  char		*word;
  int		color;
  int		key;
  int		i;
  int		j;
  int		k;
}		t_param;

void		fill_grid(t_param *, t_map *);
int		create_grid(t_param *);
t_map		**create_map(t_param *);

#endif /* !MY_H_ */
