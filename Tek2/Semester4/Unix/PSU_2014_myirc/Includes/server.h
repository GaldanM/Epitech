/*
** for  in /home/moulin_c/rendu/NewIRC/IRC/Sources/Server
**
** Made by MOULINNEUF Galdan
** Login   <moulin_c@epitech.net>
**
** Started on  Sat Apr 11 14:22:13 2015 MOULINNEUF Galdan
** Last update Sun Apr 12 22:50:46 2015 MOULINNEUF Galdan
*/

#ifndef _SERVER_H_
# define  _SERVER_H_

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/time.h>
# include		<unistd.h>
# include		<stdio.h>
# include		<string.h>
# include		<stdlib.h>

# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2

# define MAX_FD		255

# define EXIT_FAIL	-1
# define EXIT_SUCCESS	0

# define NO_CHANNEL	0
# define CHANNEL	1

typedef struct		s_channel
{
  char			*name;
  int			flag;
  struct s_lclient	*clients;
  struct s_channel	*next;
}			t_channel;

typedef struct		s_client
{
  char			*nick;
  int			fd;
  struct s_lchannel	*channels;
  struct s_client	*next;
}			t_client;

typedef t_client *(*fct)();

typedef struct		s_env
{
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			port;
}			t_env;

typedef struct		s_param
{
  t_env			e;
  int			fd_max;
  fd_set		fd_read;
  fd_set		fd_write;
  struct timeval	tv;
  char			*ret;
}			t_param;

typedef struct		s_lclient
{
  t_client		*cl;
  struct s_lclient	*next;
}			t_lclient;

typedef struct		s_lchannel
{
  t_channel		*ch;
  struct s_lchannel	*next;
}			t_lchannel;


/*
** INIT_SERVER
*/

int			add_server(t_env *);
int			init_server(t_param *, char *);

/*
** CLIENT_READ
*/

t_client		*client_read(t_channel *, t_client *, t_env *, int);

/*
** SERVER_READ
*/

int			add_client(t_channel *, t_client **,  int);
int			set_env(t_env *, int);
t_client		*server_read(t_channel *, t_client *, t_env *, int);

/*
** LIST_CHANNEL
*/

t_channel		*init_channel();
t_channel		*add_channel(t_channel *, char *);
void			remove_channel(t_channel *, t_channel *);

/*
** LIST_CLIENT
*/

void			remove_client_from_channel(t_channel *, t_client *);
void			remove_channel_from_client(t_client *, t_channel *);
int			add_client_to_channel(t_client *, t_channel *);
void			move_client(t_channel *, t_channel *, t_channel *, int);
int			add_channel_to_client(t_channel *, t_client *);

/*
** EXEC_SERVER
*/

void			set_fd(t_param *);
t_client		*check_fds(t_param *, t_channel *, t_client *);
int			server_exec(t_param *, t_channel *, t_client *);

/*
** FONCS_LIST
*/

t_channel		*get_channel_from_name(t_channel *, char *);
t_channel		*get_channel_from_client(t_channel *, int);
t_client		*get_client_from_nick(t_client *, char *);
t_client		*get_client_from_fd(t_client *, int);

/*
** STR_TO_TAB
*/

int			my_wdlen(char *s);
int			count_ord(char *s);
char			**str_to_tab(char *s);

/*
** CMDS
*/

int			change_nick(t_channel *, t_client *, int, char **);
int			display_channels(t_channel *, t_client *, int, char **);
int			join_channel(t_channel *, t_client *, int, char **);
int			quit_channel(t_channel *, t_client *, int, char **);
int			display_users(t_channel *, t_client *, int, char **);
int			msg_to_user(t_channel *, t_client *, int, char **);
int			msg_to_channel(t_channel *, t_client *,  int, char **);

/*
** FONC_ADD_CLIENT
*/

t_lchannel		*init_lchannel(t_channel *);
t_client		*init_client(int, t_lchannel *);
t_lclient		*init_lclient(t_client *);
void			put_lcl_channel(t_lclient *, t_channel *);
void			put_cl_to_cl(t_client *, t_client **);

#endif /* !_SERVER_H_ */
