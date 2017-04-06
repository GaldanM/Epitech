/*
** alum.h for alum1 in /home/moulin_c/rendu/Semester 2/Modules/C_Prog_Elem/Alum_1/Allum1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Feb  4 12:19:46 2014 moulin_c
** Last update Fri Feb  7 16:34:16 2014 moulin_c
*/

#ifndef ALUM_H_
# define ALUM_H_

# include <stdlib.h>
# include <ncurses/curses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

# define TURN_CMP(turn)		((turn) == (1) ? (3) : (1))
# define TURN_PLYR(turn)	((turn) == (1) ? (2) : (1))

typedef struct	s_param
{
  int	i;
  int	j;
  int	lines_max;
  int	space;
  int	nb_alum;
  char	turn;
  char	mode;
  char	player1[100];
  char	player2[100];
}		t_param;

typedef struct	s_alum
{
  char	taken;
  char	select;
  char	on_it;
  char	letter;
}		t_alum;

int	ask_lines(t_param *var);
int	ask_players(t_param *var);
int	ask_players_2(t_param *var, char *buffer);

int	check_line(t_alum **tabl, int i);
void	del_line(t_param *var, t_alum **tabl, int i);
int	computer_turn(t_param *var, t_alum **tabl);

void	display(t_param *var, t_alum **tabl);
void	disp_error(void);
int	disp_lost(t_param *var);

int	do_it(int nb);
int	do_caps(char *str);

void	fill_line(t_alum **tabl, int i, int stat);
t_alum	**create_list(int nb_lines);
void	disp_list(t_param *var, t_alum **tabl, int i);
void	disp_matches(t_param *var, t_alum **tabl);

int	game_computer(t_param *var, t_alum **tabl);
int	game_players(t_param *var, t_alum **tabl);
int	game(t_param *var, t_alum **tabl);

void	gere_enter(t_param *var, t_alum **tabl);

void	unselect_tabl(t_param *var, t_alum **tabl);
int	check_select(t_param *var, t_alum **tabl);

void	gere_up(t_param *var, t_alum **tabl);
void	gere_down(t_param *var, t_alum **tabl);
void	gere_left(t_param *var, t_alum **tabl);
void	gere_right(t_param *var, t_alum **tabl);
void	gere_arrows(char *buffer, t_param *var, t_alum **tabl);

void	unselect_all(t_param *var, t_alum **tabl);
int	check_last(t_param *var, t_alum **tabl);
int	check_selections(t_param *var, t_alum **tabl);
void	gere_select(t_param *var, t_alum **tabl);

int	calc_matches(int lines_max);
int	check_read(char *buffer);
int	init_param(t_param *var);
int	init(struct termios *term, struct termios *prev, t_param *var);
int	main(int argc, char **argv);

int	read_key(t_param *var, t_alum **tabl);

#endif /* !ALUM_H_ */
