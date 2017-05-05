/*
** editor.h for  in /home/moulin_c/rendu/epic_js_fantasy
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sun May 11 20:52:49 2014 moulin_c
** Last update Sun May 11 21:37:08 2014 moulin_c
*/

#ifndef EDITOR_H_
# define EDITOR_H_

#include "worldeditor.h"
#include "get_next_line.h"
#include "write.h"

typedef struct	s_rooms
{
  struct s_rooms	*prev;
  struct s_champs	*champ;
  struct s_monsts	*monst;
  char			*name;
  int			room_id;
  int			root;
  char			*connect;
  char			*monster;
  int			nb_monst;
  int			adv;
  struct s_rooms	*next;
}		t_rooms;

char	*my_recup_name(int, char *, char *);
void	set_monsters(int, char *);
void	set_connections(int, t_rooms *);
void	set_adv(int);
void	set_rooms(int, t_rooms **);
void	set_armor(int);

void	aff_str(char *, char *);
int	my_verif_nbr(char *, int , char *);

void	my_putchar_file(int, int);
int	my_putstr_file(char *, int, int);

char	*my_recup_name(int, char *, char *);
t_rooms	*make_rooms(void);
void	add_room(t_rooms **, int, char *);

char	*strcpy_getnextline(char *, char *);
char	*my_realloc_line(char *);
int	buff_read(const int *, char *, int *, int *);
char	*get_next_line(const int fd);

void	get_monsters(int, int);
void	get_chars(int, int);
int	get_data(t_rooms **, int);
void	get_rooms(t_rooms **, int, int);

void	header_file(char *, t_rooms **, int);

int	my_putnbr_param(int, int, int);

t_rooms	*make_rooms();
char	*my_recup_name();

void	set_weapon(int);
void	set_stats(int);
void	make_map(t_rooms **, int);
int	my_put_header(t_rooms **, int);

char	*rev_str(char *);

#endif /* !EDITOR_H_ */
