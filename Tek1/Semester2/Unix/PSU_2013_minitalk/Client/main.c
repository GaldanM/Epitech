/*
** main.c for minitalk in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minitalk/PSU_2013_minitalk/Client
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Mar 20 11:29:16 2014 moulin_c
** Last update Sat Mar 22 17:28:37 2014 moulin_c
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../minitalk.h"

int	main(int argc, char **argv)
{
  int	pid_serv;
  int	pid_cl;

  if (argc == 3)
    {
      pid_serv = my_getnbr(argv[1]);
      if (pid_serv < 1 || kill(pid_serv, SIGUSR1) == -1)
	{
	  my_putstr("Wrong Server PID\n");
	  return (-1);
	}
      pid_cl = getpid();
      usleep(100);
      send_pid(pid_cl, pid_serv);
      signal(SIGUSR1, do_nothing);
      sleep(4);
      send_text(argv[2], pid_serv);
      my_putstr("Message sent successfully !\n");
    }
  else
    my_putstr("Usage : ./client [PID Server] [Message]\n");
  return (0);
}
