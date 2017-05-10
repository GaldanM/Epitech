/*
** main.c for main in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:29:40 2015 Fares Doghri
** Last update Sun Jul  5 23:29:52 2015 Fares Doghri
*/

#include		"server.h"

static int 			g_fd_s;

void			catched(int signo)
{
  (void)signo;
  close(g_fd_s);
}

int 			main(int argc, char **argv)
{
  t_param		p;

  if ((signal(SIGPIPE, SIG_IGN) == SIG_ERR)
      || (signal(SIGINT, catched) == SIG_ERR))
    return (FALSE);
  if (argc < 12)
    {
      fprintf(stderr, "Usage : ./server -p [PORT] -x [WIDTH] -y [HEIGHT] ");
      fprintf(stderr, "-n [TEAM_1] [TEAM_2]... -c [CLIENTS_MAX PER TEAM] ");
      fprintf(stderr, "-t [TEMPORAL UNIT IN SECONDS]\n");
      return (FALSE);
    }
  if (init_all(&p, argv) == FALSE
      || ((g_fd_s = p.fd_s) != p.fd_s)
      || exec_server(&p) == FALSE)
    {
      close(g_fd_s);
      return (FALSE);
    }
  close(g_fd_s);
  return (TRUE);
}
