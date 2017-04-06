/*
** server.c for server in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minitalk/TP/test_pong
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Mar 13 18:19:44 2014 moulin_c
** Last update Sun Mar 23 23:24:51 2014 moulin_c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include "../minitalk.h"

#define		MASK_PID	65536
#define		MASK_CHAR	256

int		g_nb;

void		sig_char(int signum)
{
  static int	save = 0;

  if (signum == SIGUSR1)
    g_nb = (0 << save) | g_nb;
  else if (signum == SIGUSR2)
    g_nb = (1 << save) | g_nb;
  save++;
  if (save == 8)
    {
      g_nb = (1 << save) | g_nb;
      save = 0;
    }
}

void		sig_pid(int signum)
{
  static int	save = 0;

  if (signum == SIGUSR1)
    g_nb = (0 << save) | g_nb;
  else if (signum == SIGUSR2)
    g_nb = (1 << save) | g_nb;
  save++;
  if (save == 16)
    {
      g_nb = (1 << save) | g_nb;
      save = 0;
    }
}

int		get_client_pid()
{
  int		bit;

  g_nb = 0;
  bit = 0;
  while (!bit)
    {
      if (signal(SIGUSR1, sig_pid) == SIG_ERR)
	{
	  my_putstr("Signal func failed\n");
	  exit(1);
	}
      if (signal(SIGUSR2, sig_pid) == SIG_ERR)
	{
	  my_putstr("Signal func failed\n");
	  exit(1);
	}
      usleep(100);
      bit = g_nb >> 16;
      if (bit == 1)
      	return (g_nb - MASK_PID);
    }
  return (0);
}

void		check_bit(int *end)
{
  int		bit;

  bit = g_nb >> 8;
  if (bit == 1)
    {
      g_nb = g_nb - MASK_CHAR;
      if (!g_nb)
	*end = 1;
      else
	my_putchar(g_nb);
      g_nb = 0;
    }
}

void		aff_text(int pid_cl)
{
  int		end;

  my_putstr("] Message from client : '");
  g_nb = 0;
  end = 0;
  while (!end)
    {
      if (signal(SIGUSR1, sig_char) == SIG_ERR)
	{
	  my_putstr("Signal func failed\n");
	  exit(1);
	}
      if (signal(SIGUSR2, sig_char) == SIG_ERR)
	{
	  my_putstr("Signal func failed\n");
	  exit(1);
	}
      usleep(100);
      check_bit(&end);
      if (kill(pid_cl, SIGUSR1) == -1)
	{
	  my_putstr("\nClient unreachable, please restart server\n");
	  end = 1;
	}
    }
}
