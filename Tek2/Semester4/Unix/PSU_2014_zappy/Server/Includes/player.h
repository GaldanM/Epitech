#ifndef PLAYER_H_
# define PLAYER_H_

# include			<time.h>
# include			<stdlib.h>
# include     "action.h"
# include     "egg.h"
# include     "case.h"

typedef enum      e_status
{
    PLAYER = 0,
    GHOST
}                 e_status;

typedef enum    	e_direction
{
  N = 0,
  E,
  S,
  O
}					        e_direction;

typedef struct      s_player
{
  char              root;
  e_direction       direction;
  e_status          status;
  int               y;
  int               x;
  int				        id;
  int               lvl;
  char              *team;
  t_action          *actions;
  char              sound[8];
  double               time;
  struct timeval    start;
  int               inventory[7];
  struct s_player   *next;
}                   t_player;

/*
**	FONCS
*/
t_player      *init_player_list();
e_bool 				push_player(t_player**, t_player*);
void          init_player(t_player*, t_player*);
e_bool 				delete_player(t_player**, int);
int           count_players_case(t_player*, int, int, int);

#endif /* !PLAYER_H_ */