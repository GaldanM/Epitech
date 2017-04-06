/*
** client.c for client in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minitalk/TP/test_pong
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Mar 13 18:18:11 2014 moulin_c
** Last update Sun Mar 23 23:24:20 2014 moulin_c
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../minitalk.h"

void	my_send(char c, int pid_serv, int a)
{
  if (c == '0')
    {
      if (kill(pid_serv, SIGUSR1) == -1)
	{
	  my_putstr("Server unreachable, please restart server and client\n");
	  exit(1);
	}
    }
  else if (c == '1')
    {
      if (kill(pid_serv, SIGUSR2) == -1)
	{
	  my_putstr("Server unreachable, please restart server and client\n");
	  exit(1);
	}
    }
  signal(SIGUSR1, do_nothing);
  if (a == 1)
    sleep(4);
  else
    usleep(300);
}

void	send_sig(char c, int pid_serv)
{
  char	*bin;
  int	i;

  if ((bin = my_get_nbr_base(c, "01", 8)) == NULL)
    {
      my_putstr("Malloc failed\n");
      exit(1);
    }
  i = 0;
  while (bin[i])
    {
      my_send(bin[i], pid_serv, 1);
      i++;
    }
  free(bin);
}

void	send_pid(int pid_cl, int pid_serv)
{
  char	*bin;
  int	i;

  if ((bin = my_get_nbr_base(pid_cl, "01", 16)) == NULL)
    {
      my_putstr("Malloc failed\n");
      exit(1);
    }
  i = 0;
  while (bin[i])
    {
      my_send(bin[i], pid_serv, 0);
      i++;
    }
  free(bin);
}

void	send_text(char *str, int pid_serv)
{
  int	i;

  i = 0;
  while (str[i])
    {
      send_sig(str[i], pid_serv);
      i++;
    }
  send_sig(str[i], pid_serv);
}
