/*
** worldeditor.h for worldeditor in /home/di-mam_a/rendu/Rush 2/lib
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Sat May 10 19:03:01 2014 di-mam_a
** Last update Sat May 10 20:14:49 2014 di-mam_a
*/

#ifndef	WORLDEDITOR_H_
# define WORLDEDITOR_H_

# define WARRIOR	1;
# define WIZARD		2;
# define TEMPLAR	3;

typedef struct	s_map
{
  struct s_map	*prev;
  char		*name;
  int		room_id;
  int		root;
  struct s_map	*next;
}		t_map;

#endif	/* WORDEDITOR_H_ */
