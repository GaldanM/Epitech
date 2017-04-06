/*
** parser.c for minishell in /home/moulin_c/rendu/Semester 2/Modules/Unix/Minishell/Minishell_2/PSU_2013_minishell2
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Fri Feb 14 18:51:31 2014 moulin_c
** Last update Sun Mar  9 21:33:46 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/my.h"
#include "../Includes/parser.h"
#include "../Includes/shell.h"

int	count_cmds(char **tab)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (tab[i] != NULL)
    {
      if (!my_strcmp(tab[i], "|") || !my_strcmp(tab[i], ";")
	  && tab[i + 1] != NULL)
	nb++;
      i++;
    }
  return (nb + 1);
}

void	fill_dbl_tab(t_cmd *tab_p, char **tab, t_fd *var)
{
  var->end = var->i - 1;
  if ((tab_p[var->j].cmd =
       malloc(sizeof(char *) * (var->end - var->beg + 2))) == NULL)
    exit(2);
  var->a = 0;
  while (var->beg <= var->end)
    {
      tab_p[var->j].cmd[var->a] =
	my_strcpy(tab_p[var->j].cmd[var->a], tab[var->beg]);
      var->beg++;
      var->a++;
    }
  tab_p[var->j].cmd[var->a] = NULL;
}

void 	fill_tab_struct(t_cmd *tab_p, char **tab, t_fd *var)
{
  var->beg = var->i;
  while (tab[var->i] && CMP_REDIR_DIF(tab[var->i]))
    (var->i)++;
  if (var->key < 1)
    fill_dbl_tab(tab_p, tab, var);
  fill_fd(tab_p, tab, var);
  if (tab[var->i] != NULL && var->key == 0)
    (var->j)++;
  if (tab[var->i] != NULL && !my_strcmp(tab[var->i], ";"))
    comma(var);
  if (tab[var->i] != NULL && (CMP_REDIR_EG(tab[var->i])))
    var->key = 1;
  if (tab[var->i] != NULL)
    (var->i)++;
}

void	fill_tab_p(t_cmd *tab_p, char **tab)
{
  t_fd	var;

  var.i = 0;
  var.j = 0;
  var.pipefd[0] = 0;
  var.pipefd[1] = 1;
  var.key = 0;
  while (tab[var.i])
    fill_tab_struct(tab_p, tab, &var);
}
