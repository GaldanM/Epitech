/*
** main.c for mysh in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed Dec 11 17:54:20 2013 moulin_c
** Last update Sun Mar  9 21:30:12 2014 moulin_c
*/

#include <stdlib.h>
#include <signal.h>
#include "../Includes/shell.h"
#include "../Includes/get_next_line.h"
#include "../Includes/parser.h"
#include "../Includes/my.h"

void	get_signal(pid_t pid)
{
  my_putstr("\nMinishell_2 > ");
}

int	my_shell(char ***envp)
{
  t_cmd	*tab_p;
  char	**tab;
  char	*str;
  int	nb;

  my_putstr("Minishell_2 > ");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (!str[0])
    return (0);
  tab = my_str_to_wordtab(str);
  if (REDIRECT_EG(tab[0][0]))
    {
      my_putstr("Syntax error\n");
      return (0);
    }
  nb = count_cmds(tab);
  if ((tab_p = malloc(sizeof(t_cmd) * (nb + 1))) == NULL)
    return (-1);
  tab_p[nb].cmd = 0;
  fill_tab_p(tab_p, tab);
  exec_loop(tab_p, envp);
  return (0);
}

int	main(int argc, char **argv, char **envp)
{
  if (signal(SIGINT, get_signal) == SIG_ERR)
    return (-1);
  while (42)
    {
      if (my_shell(&envp) == -1)
	{
	  my_putchar('\n');
	  return (-1);
	}
    }
}
