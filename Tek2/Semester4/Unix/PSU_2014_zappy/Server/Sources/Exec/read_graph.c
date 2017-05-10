/*
** read_graph.c for read_graph in /home/doghri_f/rendu/PSU_2014_zappy/Server/Sources/Exec
** 
** Made by Fares Doghri
** Login   <doghri_f@epitech.net>
** 
** Started on  Sun Jul  5 23:30:49 2015 Fares Doghri
** Last update Sun Jul  5 23:30:56 2015 Fares Doghri
*/

#include	"server.h"

e_bool		read_graph(t_param *p, int fd_c)
{
  int		ret;
  char	*buff;
  char	**cmds;

  if ((buff = get_next_line(fd_c, &ret)) != NULL)
    {
      if ((cmds = str_to_tab(buff)) == NULL)
	return (FALSE);
      exec_cmd_graph(p, cmds, fd_c);
    }
  if (ret <= 0)
    {
      fprintf(stderr, "Client graph [%d] left !\n", fd_c);
      delete_graph(&(p->graphs), fd_c);
      p->fd_type[fd_c] = FD_FREE;
      if (close(fd_c) == FALSE)
	return (FALSE);
    }
  return (TRUE);
}

e_bool		exec_cmd_graph(t_param *p, char **cmds, int fd_c)
{
  void		(*func)();
  char		**tab;

  if (((tab = create_tab_cmd_graph()) == NULL)
      || (cmds[0] == NULL)
      || ((func = (void (*)())search_func_graph(tab, cmds)) == NULL))
    {
      dprintf(fd_c, "\"%s\" is not a correct command\n", cmds[0]);
      return (FALSE);
    }
  p->cmds = cmds;
  (*func)(p, fd_c);
  return (TRUE);
}

char		**create_tab_cmd_graph()
{
  char		**cmd;

  if ((cmd = malloc(9 * sizeof(char *))) == NULL)
    return (NULL);
  if (!(cmd[0] = strdup("msz"))
      || (!(cmd[1] = strdup("bct")))
      || (!(cmd[2] = strdup("mct")))
      || (!(cmd[3] = strdup("tna")))
      || (!(cmd[4] = strdup("ppo")))
      || (!(cmd[5] = strdup("plv")))
      || (!(cmd[6] = strdup("pin")))
      || (!(cmd[7] = strdup("sgt")))
      || (!(cmd[8] = strdup("sst"))))
    return (NULL);
  return (cmd);
}

void		*search_func_graph(char **tab, char **cmds)
{
  int		i;
  void		(*func[10])();

  func[0] = &msz;
  func[1] = &bct_case;
  func[2] = &bct_map;
  func[3] = &tna;
  func[4] = &ppo;
  func[5] = &plv;
  func[6] = &pin;
  func[7] = &sgt_send;
  func[8] = &sgt_set;
  func[9] = &suc;
  i = 0;
  while (i < 9)
    {
      if (!strcmp(tab[i], cmds[0]))
	{
	  free_tab(tab, 9);
	  return (func[i]);
	}
      ++i;
    }
  free_tab(tab, 9);
  return (func[9]);
}
