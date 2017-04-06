/*
** main.c for minitalk in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minitalk/PSU_2013_minitalk/Server
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Mar 20 11:27:09 2014 moulin_c
** Last update Sat Mar 22 17:23:18 2014 moulin_c
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../minitalk.h"

int		main()
{
  int		pid_cl;
  int		count;

  my_putstr("PID Server : ");
  my_put_nbr(getpid());
  my_putchar('\n');
  count = 1;
  while (42)
    {
      my_putstr("Waiting...\n");
      signal(SIGUSR1, do_nothing);
      pause();
      pid_cl = get_client_pid();
      if (kill(pid_cl, SIGUSR1) == -1)
	{
	  my_putstr("Error : Wrong Client PID\n");
	  return (-1);
	}
      my_putchar('[');
      my_put_nbr(count);
      aff_text(pid_cl);
      my_putstr("'\n");
      count++;
    }
  return (0);
}
