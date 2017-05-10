#ifndef EGG_H_
# define EGG_H_

# include           <sys/time.h>
# include           "case.h"

typedef struct      s_egg
{
  char              root;
  int               y;
  int               x;
  e_bool            hatched;
  int               id_player;
  int               id;
  char              *team;
  long long         time;
  struct timeval    start;
  struct s_egg      *next;
}                   t_egg;

/*
**	FONCS
*/
t_egg         *init_eggs();
e_bool 				push_egg(t_egg**, t_egg*);
e_bool 				delete_egg(t_egg**, int);

#endif /* !EGG_H_ */