/*
** main.c for test in /home/js/last_rush/lib
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Sat May 10 04:14:58 2014 thibau_j
** Last update Sun May 11 20:31:46 2014 moulin_c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "fantasy.h"

void		function_read(char *buff)
{
  char		tab[1024];
  int		ret;

  printf("%s\n", buff);
  if (write(1, "client> ", 8) == -1)
    exit(EXIT_FAILURE);
  if ((ret = read(0, tab, 1024)) == -1)
    exit(EXIT_FAILURE);
  tab[ret] = '\0';
  write_on_server(tab, strlen(tab));
}

int		main(int ac, char **av)
{
  if (ac < 2)
    {
      printf("./client nb_port\n");
      return (-1);
    }
  if (client_init(NULL, atoi(av[1]), function_read) == -1)
    return (-1);
  client_loop();
  return (1);
}
