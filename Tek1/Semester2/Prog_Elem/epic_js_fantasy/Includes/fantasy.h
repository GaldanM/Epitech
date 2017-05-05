/*
** fanstasy.h for fastasy in /home/di-mam_a/rendu/Rush 2/lib
** 
** Made by di-mam_a
** Login   <di-mam_a@epitech.net>
** 
** Started on  Sat May 10 11:54:10 2014 di-mam_a
** Last update Sun May 11 21:31:04 2014 moulin_c
*/

#ifndef	FANTASY_H_
# define FANTASY_H_

# define WARRIOR	1;
# define WIZARD		2;
# define TEMPLAR	3;

# include "get_next_line.h"
# include "network_client.h"
# include "network_server.h"
# include "worldeditor.h"
# include "write.h"

typedef struct	s_rooms
{
  struct s_rooms	*prev;
  struct s_champs	*champ;
  struct s_monsts	*monst;
  char			*name;
  char			*connect;
  char			*monster;
  int			nb_monst;
  int			adv;
  struct s_rooms	*next;
}		t_rooms;

typedef struct	s_monsts
{
  struct s_monsts	*prev;
  char			*type;
  char			*weapon;
  char			*armor;
  int			hp;
  int			spe;
  int			spd;
  int			deg;
  struct s_monsts	*next;
}		t_monsts;

typedef struct	s_champs
{
  struct s_champs	*prev;
  char			*name;
  char			*type;
  char			*weapon;
  char			*armor;
  int			hp;
  int			spe;
  int			spd;
  int			deg;
  struct s_champs	*next;
}		t_champs;

typedef struct	s_header
{
  char		*name;
  char		*start;
  char		*end;
  t_rooms	*list_rooms;
  t_champs	*list_champs;
  t_monsts	*list_monsts;
}		t_header;

void		add_champ(t_champs **champs, t_champs *champ);
void		add_monst(t_monsts **monsts, t_monsts *monst);
void		add_room(t_rooms **rooms, t_rooms *room);

char		*recup_str(int *i, char *line);
void		fill_header(t_header *header, char *line, int i);
void		fill_champ2(char *line, int i, t_champs *champ);
void		fill_champ(t_header *header, char *line, int i);
void		fill_monster(t_header *header, char *line, int i);
void		fill_room(t_header *header, char *line, int i);

void		my_exitstr(char *error);
void		init_header(t_header *header);
void		analyse_line(char *line, t_header *header);
void		parser(char *file, t_header *header);

t_rooms		*make_rooms(void);
t_champs	*make_champs(void);
t_monsts	*make_monsts(void);

#endif	/* FANTASY_H_ */
