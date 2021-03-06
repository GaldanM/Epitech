/*
** graph.h for  in /home/medec_o/rendu/lem_in/code_tek
** 
** Made by medec_o
** Login   <medec_o@epitech.net>
** 
** Started on  Thu Apr 24 12:13:36 2014 medec_o
** Last update Sat Apr 26 19:32:05 2014 moulin_c
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include "mylist.h"

# define	SPACES(car)		(car == ' ' || car == '\t')

typedef struct	s_adj_list
{
  char			*name;			/* identifiant du salles */
  int			nb_adj;			/* nombre de sommet adjacent */
  char			**adjacents;		/* tableau des sommets adjacents */
  int			*cout;
  int			flag;
  int			nb_ant;
  struct  s_adj_list	*next;
}		t_adj;

typedef struct	s_graphe
{
  int			nb_rooms;		/* nombre de salles */
  int			nb_arcs;		/* nombre d'arcs */
  int			nb_ants;		/* nb fourmis */
  struct s_adj_list	*adj_list;		/* liste des salles */
}		t_graphe;

void	check_function(char *line, char **tab);
char	**my_malloc_adj(char *name);
int	fill_adj(t_adj **galdan, char **tab, char *line, int flag);
int	add_adjacent(t_adj **galdan, char *line);
void	fill_pipes(t_adj **galdan, t_list **olivier);

int	check_line(char *line);
int	count_letters(char *line);
char	**my_malloc_tab(char *line);
int	my_show_tab(char **tab);

int	find_pipe(char *str);
int	add_room(t_adj **list, char *line, int flag);
int	new_room(char *str);
int	fill_list(t_adj **list, t_list **lines);
void	get_nb_adj(t_adj **list);

int	my_tablen(char **tab);
char	**my_tabcpy(char **old, char **new);
char	**my_tab_realloc(char **old, int size, char *line);
char	**my_str_to_word_tab(char *line, char **tab);

#endif /* !GRAPH_H_ */
