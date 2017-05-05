/*
** network.h for network.h in /home/js/rush_bocal/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sun May  4 21:20:40 2014 thibau_j
** Last update Sun May 11 20:32:07 2014 moulin_c
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef struct		s_network
{
  int			socket;
  int			mode;
  char			*data;
  size_t		size;
  void			(*listen_read)(char *buff, size_t size);
}			t_network;

/*
** Init your connection, use it before your loop for initialize
** your connection, it returns 0 if everythings ok. You can configure the address
** and the port but if you put NULL and 0 it will be 127.0.0.1 and 4242 by default.
*/

int			client_init(char *ip, int port,
				    void (*fct_read)(char *buff));
/*
** client loop, it will call your read function.
*/

void			client_loop();

/*
** write_on_server will set to write mode and cpy buff for being write on the server.
*/

void			write_on_server(char *buff, size_t size);

#endif			/* !NETWORK_H_ */
