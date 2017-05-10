#ifndef SERVER_H_
# define SERVER_H_

# define                  _GNU_SOURCE
# define                  FD_FREE   0
# define                  FD_CLIENT 1
# define                  FD_IA     2
# define                  FD_GRAPH  3
# define                  FD_SERVER 4
# define                  MAX_FD    255

# include			      	<sys/types.h>
# include			      	<sys/socket.h>
# include			      	<netinet/in.h>
# include			      	<arpa/inet.h>
# include			      	<sys/time.h>
# include			      	<unistd.h>
# include			      	<stdio.h>
# include			        <string.h>
# include             <stdlib.h>
# include             <math.h>
# include             <signal.h>
# include             "case.h"
# include             "player.h"
# include             "graph.h"
# include             "get_next_line.h"

typedef struct      s_option
{
  int       p;
  int       x;
  int       y;
  int       c;
  int       n;
  int       t;
}       t_option;

typedef e_bool             	(*fct_ptr)();

typedef struct          	s_param
{
  int             port;
  int 						size_y;
  int 						size_x;
  int 						delay;
  int             clients_max;
  int             *clients_team;
  char            **team_name;

  int                     fd_s;
  int                   	fd_max;
  fd_set                	fd_read;
  fd_set                	fd_write;
  char                  	fd_type[MAX_FD];
  fct_ptr               	fct_read[MAX_FD];
  fct_ptr               	fct_write[MAX_FD];
  struct timeval        	tv;
  char                    **cmds;
  t_graph                 *graphs;
  t_player                *players;
  t_egg                   *eggs;
  t_case                	***map;
}					       	t_param;

typedef struct      s_p_look
{
  t_param           *p;
  t_player          *tmp;
  int               r_y;
  int               r_x;
  int               r_max;
  int               y;
  int               x;
}                   t_p_look;

void  south_east(t_param *p, t_player *dest, int new_y, int new_x);
void  north_east(t_param *p, t_player *dest, int new_y, int new_x);
void  south_west(t_param *p, t_player *dest, int new_y, int new_x);
void  north_west(t_param *p, t_player *dest, int new_y, int new_x);
void    init_funcs(void   (*func[13])());

/*
**  FONCS_DIVERS.C
*/
char        *my_strcat(char*, char*);
int         my_strlen(char*);
int   get_team_id(char**, char*);
t_player  *get_player_by_id(t_param *p, int id);

/*
** INIT_ALL.C
*/
e_bool        init_all(t_param*, char**);
e_bool        init_server(t_param*);
e_bool        init_param(t_param*, char**, t_option*);
e_bool        init_map(t_param*);
e_bool        init_max_clients(t_param*);


/*
** INIT_OPTION.C
*/
void        init_option(t_option*);
e_bool        check_value_option(t_option*);

/*
** CHECK_OPTION.C
*/
e_bool        check_options(char**);
e_bool        not_option(char*);

/*
** INIT_PORT.C
*/
int       set_port(char*);
e_bool        check_port(t_param*, char**, int, t_option*);

/*
** INIT_WIDTH.C
*/
int       set_width(char*);
e_bool        check_width(t_param*, char**, int, t_option*);

/*
** INIT_HEIGHT.C
*/
int       set_height(char*);
e_bool        check_height(t_param*, char**, int, t_option*);

/*
** INIT_PLAYER.C
*/
int       set_players(char*);
e_bool        check_players(t_param*, char**, int, t_option*);

/*
** INIT_DELAY.C
*/
int       set_delay(char *);
e_bool        check_delay(t_param*, char **, int, t_option*);

/*
** INIT_TEAM.C
*/
int       set_team(t_param*, char**, int, int);
e_bool        check_team(t_param*, char**, int, t_option*);

/*
** EXEC_SERVER.C
*/
e_bool				            exec_server(t_param*);
void				              set_fds(t_param*);
e_bool				            check_fds(t_param*);

/*
** READ_SERVER.C
*/
e_bool                     read_server(t_param*, int);

/*
** READ_CLIENT.C
*/
e_bool                     read_client(t_param*, int);
e_bool                     connect_graphic(t_param*, int);
e_bool                     connect_ia(t_param*, char*, int);
void                        spawn_ressources(t_param*);
void            start_graph(t_param *p, int id);
e_bool                      check_ghosts(t_param*, char*);
e_bool                      connect_ghost(t_param*, char*, int);
e_bool                     check_team_exist(t_param*, char*, int);
e_bool                     nb_player_team(t_param*, char*, int);

/*
**  READ_IA.C
*/
e_bool                    read_ia(t_param*, int);
e_bool                    exec_cmd(t_param*, char**, int);
char                      **create_tab_cmd();
void                      *search_func(char**, char**);
void                      free_tab(char**, int);

/*
**  READ_GRAPH.C
*/
e_bool                    read_graph(t_param*, int);

/*
**  STR_TO_TAB.C
*/
char                      **str_to_tab(char*);
int                       init_var(int*, int*, int*, char*);
int                       count_word(char *s);
int                       my_wdlen(char*);

/*
**  FORWARD.C
*/
void    push_forward(t_param*, int);
void    forward(t_param*, t_player*);
void    go_north(t_param*, t_player*);
void    go_east(t_param*, t_player*);
void    go_west(t_param*, t_player*);
void    go_south(t_param*, t_player*);

/*
**  TURN.C
*/
void    push_right(t_param*, int);
void    right(t_param*, t_player*);
void    push_left(t_param*, int);
void    left(t_param*, t_player*);
void    set_sound(t_player*, int);

/*
**  INVENTORY.C
*/
void    push_inventory(t_param*, int);
void    inventory(t_param*, t_player*);

/*
**  PUT_OBJECT.C
*/
void    push_put_object(t_param*, int);
e_bool    check_put_object(t_param*, t_player*);
void    put_object(t_param*, t_player*);
void    put_in_map(t_param*, t_player*, int);

/*
**  TAKE_OBJECT.C
*/
void    push_take_object(t_param*, int);
e_bool    check_take_object(t_param*, t_player*);
void    take_object(t_param*, t_player*);
void    take_it(t_param*, t_player*, int);

/*
**  COMMAND_NOT_FOUND.C
*/
void      push_command_not_found(t_param*, int);
void      command_not_found(t_param*, t_player*);

/*
** LOOK.C
*/
void    push_look(t_param*, int);
void      look(t_param*, t_player*);
char      *vision_north(t_param*, t_player*);
char      *vision_east(t_param*, t_player*);
char      *vision_west(t_param*, t_player*);
char      *vision_south(t_param*, t_player*);

/*
**  BROWSE_LOOK.C
*/
char      *browse_north(t_p_look*, char*);
char      *browse_east(t_p_look*, char*);
char      *browse_west(t_p_look*, char*);
char      *browse_south(t_p_look*, char*);


/*
**  GET_STR_LOOK.C
*/
char      *get_str_case(t_param*, int, int, char*);
char      *get_str_players(t_player*, int, int, char*);

/*
**  EXPULSE.C
*/
void    push_expulse(t_param*, int);
e_bool    check_expulse(t_param*, t_player*);
void    expulse(t_param*, t_player*);
void    expulse_all(t_param*, t_player*);
int     init_expulse_param(t_player*, int*, int*, e_direction*);

/*
**  CONNECT_NBR.C
*/
void      push_connect_nbr(t_param*, int);
void      connect_nbr(t_param*, t_player*);
int       count_in_team(t_param*, char*);

/*
**  FORK.C
*/
void    push_fork(t_param*, int);
void    my_fork(t_param*, t_player*);
e_bool  create_egg(t_param*, t_player*);

/*
**  BROADCAST.C
*/
void    push_broadcast(t_param*, int);
void    broadcast(t_param*, t_player*);
void    seek_angle(t_param *, t_player *src, t_player *dest);
void    compare(t_param *, t_player *src, t_player *dest, e_bool direct[2]);
int     get_new_y(t_param*, int, int, e_bool direct[2]);
int     get_new_x(t_param*, int, int, e_bool direct[2]);
int     calc_y_circle(int y_max, int y_s, int y_d);
int     calc_x_circle(int x_max, int x_s, int x_d);

/*
**  BROADCAST_SEEKS.C
*/
int     seek_north(t_player*, int new_y, int new_x);
int     seek_east(t_player*, int new_y, int new_x);
int     seek_west(t_player*, int new_y, int new_x);
int     seek_south(t_player*, int new_y, int new_x);
int     calc_angle(int, int);

/*
**  INCANTATION.C
*/
void    push_incantation(t_param*, int);
void    incantation(t_param*, t_player*);
e_bool    check_incantation(t_param*, t_player*);
void    get_str_incantation(t_param*, t_player*, char*);
void    up_players(t_param*, t_player*);

/*
**  MANAGE_GAME.C
*/
void    decrease_times(t_param*);
void    browse_actions(t_param*);
e_bool    check_win(t_param *p);

/*
**  MANAGE_EGGS.C
*/
t_egg   *decrease_egg(t_param*, t_egg*);
t_egg   *ghost_death(t_egg*, t_egg*);
void    hatching(t_param*, t_egg*);

/*
**  MANAGE_PLAYERS.C
*/
t_player    *decrease_food_player(t_param*, t_player*);
t_player    *player_death(t_param*, t_player*);
void        decrease_actions_player(t_player*);
void        browse_actions_player(t_param*, t_player*);

/*
**  READ_GRAPH.C
*/
e_bool    read_graph(t_param *p, int fd_c);
e_bool    exec_cmd_graph(t_param *p, char **cmds, int fd_c);
char    **create_tab_cmd_graph();
void    *search_func_graph(char **tab, char **cmds);

/*
**  FONCS_GRAPH
*/
char    *get_case(t_param *, int, int);
void     bct_case(t_param *, int, int);
void    bct_map(t_param *, int, int);
void      ebo(t_param *, int, int);
void      edi(t_param *, int, int);
void      eht(t_param *, int, int);
void      enw(t_param *, int, int);
void        enw_all(t_param *, int);
void   msz(t_param *, int, int);
void      pbc(t_param *, int, int);
void      pdi(t_param *, int, int);
void      pdr(t_param *, int, int);
void      pex(int, int);
void      pfk(t_param *, int, int);
void      pgt(t_param *, int, int);
void  pie(t_param *p, int, int);
void      pic(t_param *, int, int);
void      pin(t_param *, int, int);
void      plv(t_param *, int, int);
void      pnw(t_param *, int, int);
void      pnw_all(t_param *, int);
void       ppo(t_param *, int, int);
void    sbp(int);
void      seg(t_param *, int);
void  sgt_set(t_param *, int);
void  sgt_send(t_param *, int, int);
void      smg(t_param *, int, int);
void      suc(t_param *, int, int);
void    tna(t_param *, int, int);


#endif /* !SERVER_H_ */
