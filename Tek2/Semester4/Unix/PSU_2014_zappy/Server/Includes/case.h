#ifndef CASE_H_
# define CASE_H_

# include 			<stdio.h>
# include 			<stdlib.h>

typedef enum    e_bool
{
          TRUE = 0,
          FALSE = -1
}               e_bool;

typedef	enum 		e_ressource
{
                    NOURRITURE = 0,
                    LINEMATE,
                    DERAUMERE,
                    SIBUR,
                    MENDIANE,
                    PHIRAS,
                    THYSTAME
}                   e_ressource;

typedef struct      s_case
{
  char              root;
  e_ressource       ressource;
  struct s_case     *next;
}                   t_case;

/*
** FONCS
*/
t_case        *init_case_list();
e_bool        push_ressource(t_case**, e_ressource);
e_bool        delete_ressource(t_case**, e_ressource);
int           count_ressource(t_case*, e_ressource);
e_bool        check_ressource(t_case*, e_ressource);

#endif /* !CASE_H_ */