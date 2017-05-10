#include 	"server.h"

e_bool		read_ia(t_param *p, int fd_c)
{
	int		ret;
	char	*buff;
	char	**cmds;

  if ((buff = get_next_line(fd_c, &ret)) != NULL)
  {
      if ((cmds = str_to_tab(buff)) == NULL)
        return (FALSE);
      exec_cmd(p, cmds, fd_c);
  }
 if (ret <= 0)
 {
  fprintf(stderr, "Client [%d] left !\n", fd_c);
  delete_player(&p->players, fd_c);
  p->fd_type[fd_c] = FD_FREE;
  if (close(fd_c) == FALSE)
    return (FALSE);
  }
  return (TRUE);
}

e_bool		exec_cmd(t_param *p, char **cmds, int fd_c)
{
  void		(*func)();
  char		**tab;

  if (((tab = create_tab_cmd()) == NULL)
      || (cmds[0] == NULL)
      || ((func = (void (*)())search_func(tab, cmds)) == NULL))
    {
      dprintf(fd_c, "\"%s\" is not a correct command\n", cmds[0]);
      return (FALSE);
    }
    p->cmds = cmds;
    (*func)(p, fd_c);
    return (TRUE);
}

char		**create_tab_cmd()
{
  char		**cmd;

  if ((cmd = malloc(12 * sizeof(char *))) == NULL)
    return (NULL);
  if (!(cmd[0] = strdup("avance"))
      || (!(cmd[1] = strdup("droite")))
      || (!(cmd[2] = strdup("gauche")))
      || (!(cmd[3] = strdup("voir")))
      || (!(cmd[4] = strdup("inventaire")))
      || (!(cmd[5] = strdup("prend")))
      || (!(cmd[6] = strdup("pose")))
      || (!(cmd[7] = strdup("expulse")))
      || (!(cmd[8] = strdup("broadcast")))
      || (!(cmd[9] = strdup("incantation")))
      || (!(cmd[10] = strdup("fork")))
      || (!(cmd[11] = strdup("connect_nbr"))))
    return (NULL);
  return (cmd);
}

void    init_funcs(void   (*func[13])())
{
  func[0] = &push_forward;
  func[1] = &push_right;
  func[2] = &push_left;
  func[3] = &push_look;
  func[4] = &push_inventory;
  func[5] = &push_take_object;
  func[6] = &push_put_object;
  func[7] = &push_expulse;
  func[8] = &push_broadcast;
  func[9] = &push_incantation;
  func[10] = &push_fork;
  func[11] = &push_connect_nbr;
  func[12] = &push_command_not_found;
}

void		*search_func(char **tab, char **cmds)
{
  int		   i;
  void		(*func[13])();

  init_funcs(func); 
  i = 0;
  while (i < 12)
  	{
  		if (!strcmp(tab[i], cmds[0]))
  		{
  			free_tab(tab, 12);
	  		return (func[i]);
		  }
		++i;
    }
  free_tab(tab, 12);
  return (func[12]);
}