/*
** main.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 13:24:55 2014 moulin_c
** Last update Sun Jun  1 18:56:00 2014 doghri_f
*/

#include	<stdlib.h>
#include	<signal.h>
#include	<unistd.h>
#include	"shell.h"

static char	*g_prompt;
static int	ret_exit;

char		*prompt(t_env *env)
{
  t_env		*tmp;
  char		*prompt;

  tmp = env->next;
  while (!tmp->root)
    {
      if (!my_strcmp("USER", tmp->name))
	{
	  if ((prompt = my_strdup("(")) == NULL)
	    return (NULL);
	  if ((prompt = my_strcat(prompt, tmp->var)) == NULL)
	    return (NULL);
	  if ((prompt = my_strcat(prompt, ")-> ")) == NULL)
	    return (NULL);
	  return (prompt);
	}
      tmp = tmp->next;
    }
  return ("(42sh)-> ");
}

void		reaf_prompt()
{
  printf("\n");
  my_putstr(g_prompt);
}

t_cmds		*my_parser(t_env *env, char *prpt)
{
  t_cmds	*cmds;

 if (my_putstr(prpt) == -1)
    return (NULL);
  if ((cmds = make_cmds()) == NULL)
    return (NULL);
  if (get_cmds(cmds, env) == -1)
    return (NULL);
  if (get_fds(cmds) == -1)
    return (NULL);
  return (cmds);
}

int		my_exec_loop(t_cmds *cmds, t_env *env)
{
  t_cmds	*tmp;

  ret_exit = 0;
  tmp = cmds->next;
  while (!tmp->root)
    {
      if (check_exec(tmp))
	{
	  if (!my_strcmp(tmp->cmd, "exit"))
	    {
	      ret_exit = 1;
	      if (!tmp->args->next->arg)
		return (0);
	      return (atoi(tmp->args->next->arg));
	    }
	  if (my_exec(tmp, env) == -1)
	    return (-1);
	}
      tmp = find_next_cmd_exec(tmp);
    }
  return (0);
}

int		main(int argc, char **argv, char **envp)
{
  t_cmds	*cmds;
  t_env		*env;
  char		*prpt;
  int		ret;

  (void)argc;
  (void)argv;
  if ((env = my_init_env(envp)) == NULL)
    return (-1);
  if ((prpt = prompt(env)) == NULL)
    return (-1);
  g_prompt = prpt;
  if (signal(SIGINT, reaf_prompt) == SIG_ERR)
    return (-1);
  while (42)
    {
      if ((cmds = my_parser(env, prpt)) == NULL)
	return (-1);
      ret =  my_exec_loop(cmds, env);
      if ((ret == 0 && ret_exit == 1) || ret != 0)
	return (ret);
    }  return (0);
}
