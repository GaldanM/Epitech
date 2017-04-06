/*
** draw.h for fdf in /home/moulin_c/rendu/Modules/Igraph/TP_tpfdf
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec  5 16:17:14 2013 moulin_c
** Last update Sat Dec  7 17:12:27 2013 moulin_c
*/

#ifndef DRAW_H_
# define DRAW_H_

#include <mlx.h>
#include <stdlib.h>

typedef struct	s_param
{
  void	*init_ptr;
  void	*win_ptr;
  void	*img_ptr;
  int	x;
  int	y;
  int	x1;
  int	x2;
  int	y1;
  int	y2;
  int	bpp;
  int	size_line;
  int	endian;
  char	*data;
}		t_param;

void	proj_iso(int x, int y, int z, t_param *var);
void	draw_cas_un(t_param *var);
void	draw_cas_cinq(t_param *var);
void	draw_line(t_param *var);
void	my_put_pixel_to_image(int x, int y, t_param *var, void *img_ptr);
int	gere_expose(t_param *var);
int	gere_key(int keycode, t_param *var);
void	trace_y(t_param var);
void	trace_x(t_param var);
int	main();

#endif /* !DRAW_H_ */
