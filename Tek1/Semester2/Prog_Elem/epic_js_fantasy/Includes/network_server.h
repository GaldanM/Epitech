/*
** network_server.h for network_server.h in /home/js/rush_bocal/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon May  5 21:47:05 2014 thibau_j
** Last update Sun May 11 20:32:03 2014 moulin_c
*/

#ifndef NETWORK_SERVER_H_
# define NETWORK_SERVER_H_

# define FD_FREE 0
# define FD_CLIENT 1
# define FD_SERVER 2
# define MAX_FD 255

typedef void(*fct)();

typedef struct	s_env
{
  int		fd_type[MAX_FD];
  fct		fct_read[MAX_FD];
  fct		fct_write[MAX_FD];
  int		port;
  int		mode[MAX_FD];
  size_t	size[MAX_FD];
  char		*tab[MAX_FD];
  void		(*listen_read)(char *buff, size_t size, int id);
}		t_env;

/*
** Port can be set but if you put 0 it will be set at 4242.
*/

void			server_loop(int port, void (*listen_read)
				    (char *buff, size_t size, int id));

/*
** Close_server : use it when you want to quit the server.
*/

void			close_server();

void			write_on_client(char *buff, size_t size, int id);

#endif /* !NETWORK_SERVER_H_ */
