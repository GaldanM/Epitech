/*
** foncs_redir.c for parser in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minishell/Minishell_2/PSU_2013_minishell2/Parser
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat Mar  8 17:28:14 2014 moulin_c
** Last update Sun Mar  9 21:23:45 2014 moulin_c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../Includes/parser.h"

void		pipes(t_cmd *tab_p, char **tab, t_fd *var)
{
  int		fd;
  mode_t	mode;

  var->save = var->pipefd[0];
  if (pipe(var->pipefd) == -1)
    exit(3);
  if (var->j > 0)
    tab_p[var->j].fdin = var->save;
  else
    tab_p[var->j].fdin = 0;
  if (tab[var->i])
    tab_p[var->j].fdout = var->pipefd[1];
  else
    tab_p[var->j].fdout = 1;
}

void		chevron_left(t_cmd *tab_p, char **tab, t_fd *var)
{
  int		fd;
  mode_t	mode;

  if ((fd = open(tab[var->i + 1], O_CREAT | O_RDWR | O_APPEND, mode)) == -1)
    exit(2);
  tab_p[var->j].fdin = fd;
  tab_p[var->j].fdout = 1;
  if (!my_strcmp(tab[var->i - 2], "<"))
    {
      tab_p[var->savepos].fdin = fd;
      tab_p[var->savepos].fdout = 1;
    }
}

void		chevron_right(t_cmd *tab_p, char **tab, t_fd *var)
{
  mode_t	mode;
  int		fd;

  if (var->key == 0)
    var->savepos = var->j;
  mode = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
  if (!my_strcmp(tab[var->i], ">>"))
    {
      if ((fd = open(tab[var->i + 1], O_CREAT | O_RDWR | O_APPEND, mode)) == -1)
	exit(2);
    }
  else
    if ((fd = open(tab[var->i + 1], O_CREAT | O_RDWR | O_TRUNC, mode)) == -1)
      exit(2);
  tab_p[var->j].fdout = fd;
  tab_p[var->j].fdin = var->pipefd[0];
  if (var->i >= 2)
    if (!my_strcmp(tab[var->i - 2], ">") || !my_strcmp(tab[var->i - 2], ">>"))
      {
	tab_p[var->savepos].fdout = fd;
	tab_p[var->savepos].fdin = var->pipefd[0];
      }
}

void		comma(t_fd *var)
{
  var->key = 0;
  var->pipefd[0] = 0;
  var->pipefd[1] = 1;
}

void		fill_fd(t_cmd *tab_p, char **tab, t_fd *var)
{
  if (tab[var->i] == NULL || !my_strcmp(tab[var->i], "|"))
    pipes(tab_p, tab, var);
  else if (!my_strcmp(tab[var->i], ">"))
    chevron_right(tab_p, tab, var);
  else if (!my_strcmp(tab[var->i], "<"))
    chevron_left(tab_p, tab, var);
  else if (!my_strcmp(tab[var->i], ">>"))
    chevron_right(tab_p, tab, var);
  else
    {
      tab_p[var->j].fdin = 0;
      tab_p[var->j].fdout = 1;
    }
}
