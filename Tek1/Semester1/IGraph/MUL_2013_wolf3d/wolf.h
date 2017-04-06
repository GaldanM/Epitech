/*
** wolf.h for wolf3d in /home/moulin_c/rendu/Modules/Igraph/Wolf3D/TP/raytracer
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Jan  1 19:34:39 2014 moulin_c
** Last update Sun Jan 12 14:26:09 2014 moulin_c
*/

#ifndef WOLF_H_
# define WOLF_H_

# include <mlx.h>
# include <math.h>

# define RAD(a)		((a / 180) * M_PI)

typedef struct	s_param
{
  void		*init;
  void		*win;
  void		*img;
  char		**tab;
  int		color;
  int		lenght;
  int		width;
  int		size;
  int		pos_top;
  int		pos_bot;
  int		x;
  int		y;
  float		x1;
  float		y1;
  float		x2;
  float		y2;
  int		r;
  int		g;
  int		b;
  float		a;
  float		a_rad;
  float		orient;
  float		x0;
  float		y0;
  float		vx;
  float		vy;
  float		d;
  float		p;
  float		k;
}		t_param;

int	gere_key(int keycode, t_param *var);
int	gere_expose(t_param *var);
void	get_rgb(t_param *var);
void	my_put_pixel_to_image(t_param *var);
void	transl_up(t_param *var);
void	transl_down(t_param *var);
void	rotate_left(t_param *var);
void	rotate_right(t_param *var);
void	my_putchar(char d);
void	my_putstr(char *str);
int	my_strlen_tab_int(char *str);
int	get_y_len(char *str, int *y, int fd);
int	get_len(char *str, int *, int *y);
int	my_str_to_tabint(char *str, int x, char **tab);
char	**get_tab_int(char *str);
void	my_wall(t_param *var);
void	my_wolf(t_param *var, int i);
void	calc_vector(t_param *var, int i);
void	calc_k(t_param *var);
void	calc_size(t_param *var);
void	my_calc(t_param *var);
void	draw_cas_un(t_param *var);
void	draw_cas_cinq(t_param *var);
void	draw_line(t_param *var);
int	init_struct(t_param *var);
int	main(int argc, char **argv);

#endif /* !WOLF_H_ */
