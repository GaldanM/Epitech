/*
** for  in /home/moulin_c/rendu/NewIRC/IRC/Sources/Server
**
** Made by MOULINNEUF Galdan
** Login   <moulin_c@epitech.net>
**
** Started on  Sat Apr 11 14:22:13 2015 MOULINNEUF Galdan
** Last update Sun Apr 12 22:50:46 2015 MOULINNEUF Galdan
*/

#include "server.h"

int		main(int argc, char *argv[])
{
  t_param	p;
  t_channel	*channels;
  t_client	*clients;

  if (argc == 1)
    {
      printf("Usage : ./server [Port]\n");
      return (EXIT_FAIL);
    }
  clients = NULL;
  if ((init_server(&p, argv[1]) == EXIT_FAIL)
      || ((channels = init_channel()) == NULL)
      || (server_exec(&p, channels, clients) == EXIT_FAIL))
    return (EXIT_FAIL);
  return (EXIT_SUCCESS);
}
