/*
** setenv.c for setenv in /home/moulin_c/rendu/Modules/Unix/Minishell/Minishell_1/PSU_2013_minishell1
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Dec 26 12:56:23 2013 moulin_c
** Last update Sun Mar  9 15:06:07 2014 moulin_c
*/

#include <stdlib.h>
#include "../Includes/my.h"
#include "../Includes/parser.h"
#include "../Includes/builts.h"

int	check_setenv(char **tab)
{
  if (tab[1] == '\0')
    {
      my_putstr("Usage : setenv 'name' 'value' 'overwrite (0 or 1)'\n");
      return (1);
    }
  if (tab[2] == '\0')
    {
      my_printf("No value set for variable '%s'\n", tab[1]);
      return (1);
    }
  return (0);
}

void	set_exist(char **tab, char ***envp, int ovrwrt, int i)
{
  if (ovrwrt <= 0)
    my_printf("'%s' exist and overwrite value should be positive\n", tab[1]);
  else
    {
      envp[0][i] = my_strcat(tab[1], "=");
      envp[0][i] = my_strcat(envp[0][i], tab[2]);
    }
}

char	*set_no_exist(char **tab, char ***envp, int i)
{
  int	len;

  len = 0;
  len = my_tablen(envp[0]);
  if ((envp[0] = my_tab_realloc(envp[0], i, 0)) == NULL)
    return (NULL);
  envp[0][len] = my_strcat(tab[1], "=");
  envp[0][len] = my_strcat(envp[0][len], tab[2]);
}

int	my_setenv(char **tab, char ***envp)
{
  int	i;
  int	ret;
  int	len;
  int	ovrwrt;

  i = 0;
  ret = 1;
  if (check_setenv(tab) == 1)
    return (1);
  if (tab[3] != '\0')
    ovrwrt = my_getnbr(tab[3]);
  else
    ovrwrt = 0;
  len = my_strlen(tab[1]);
  while (envp[0] && ret != 0 && envp[0][i])
    ret = my_strncmp(tab[1], envp[0][i++], len);
  i--;
  if (!ret)
    set_exist(tab, envp, ovrwrt, i);
  else
    if ((set_no_exist(tab, envp, i) == NULL))
      return (-1);
  return (1);
}
