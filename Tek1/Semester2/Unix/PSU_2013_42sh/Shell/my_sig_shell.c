/*
** my_sig_shell.c for my_sig_shell in /home/ounajj_k
**
** Made by khamled
** Login   <ounajj_k@epitech.net>
**
** Started on  Sun May 25 10:36:00 2014 khamled
** Last update Sun May 25 20:51:14 2014 moulin_c
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define		NBSIG 11

typedef struct	s_sig
{
  int		sig;
  char		*error;
}		t_sig;

static const t_sig	g_sig[NBSIG] =
  {
    {SIGHUP, "Hangup"},
    {SIGQUIT, "42sh : Quit"},
    {SIGABRT, "Aborted"},
    {SIGBUS, "Bus error (core dumped)"},
    {SIGFPE, "Floating exception (core dumped)"},
    {SIGKILL, "Killed"},
    {SIGCHLD, "Child stopped or terminated"},
    {SIGUSR1, "User signal 1"},
    {SIGSEGV, "Segmentation fault (core dumped)"},
    {SIGUSR2, "User signal 2"},
    {SIGTERM, "Terminated"},
  };

int		gere_sig_shell(int status)
{
  int		i;

  status = WTERMSIG(status);
  i = 0;
  while (i < NBSIG)
    {
      if (status == g_sig[i].sig)
	{
	  fprintf(stderr, "%s\n", g_sig[i].error);
	  return (1);
	}
      i++;
    }
  return (0);
}
