#ifndef ACTION_H_
# define ACTION_H_

# include			<stdlib.h>
# include 			<sys/time.h>
# include			"case.h"

typedef void      (*ptr_fct)();

typedef struct      s_action
{
  char              root;
  int            	time;
  ptr_fct           fct;
  struct timeval    start;
  char				**cmds;
  struct s_action   *next;
}                   t_action;

/*
**	FONCS
*/
t_action      *init_actions();
e_bool 				push_action(t_action**, ptr_fct, double, char**);
e_bool 				delete_action(t_action**);
int 			count_actions(t_action**);

#endif /* !ACTION_H_ */