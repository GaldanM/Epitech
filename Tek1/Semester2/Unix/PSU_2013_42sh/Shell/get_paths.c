/*
** get_paths.c for 42 in /home/moulin_c/rendu/Semester 2/Modules/Unix/42sh/Minishell1/Shell
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Wed May  7 21:00:18 2014 moulin_c
** Last update Wed May 21 13:52:54 2014 moulin_c
*/

#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"

int		get_var_bin(char **envp)
{
  int		i;

  i = 0;
  while (envp[i] && my_strncmp(envp[i], "PATH", 4))
    i++;
  if (envp[i])
    return (i);
  my_putstr("PATH variable not set, can't find binaries\n");
  return (-1);
}

char		*malloc_bin_path(char *path, int i, int *end, int *start)
{
  char		*bin_path;

  *start = i++;
  while (path[i] && path[i] != ':')
    i++;
  *end = i - 1;
  if ((bin_path = malloc(sizeof(char) * (((*end) - (*start)) + 2))) == NULL)
    return (NULL);
  return (bin_path);
}

int		str_to_pathslist(t_bin *bin, char *path)
{
  int	i;
  int	end;
  int	start;
  char	*bin_path;

  i = 0;
  while (path[i] != '=')
    i++;
  i++;
  while (path[i])
    {
      if ((bin_path = malloc_bin_path(path, i, &end, &start)) == NULL)
	return (-1);
      i = 0;
      while (start <= end)
	bin_path[i++] = path[start++];
      bin_path[i] = '\0';
      if (add_bin(&bin, bin_path) == -1)
	return (-1);
      if (path[end + 1])
	i = end + 2;
      else
	i = end + 1;
    }
  return (0);
}

char		*path_bin(char *bin, t_bin *list_bin)
{
  char		*bin_tmp;
  t_bin		*tmp;

  tmp = list_bin->next;
  while (!tmp->root)
    {
      if ((bin_tmp = my_strcat(tmp->path, "/")) == NULL)
	return (NULL);
      if ((bin_tmp = my_strcat(bin_tmp, bin)) == NULL)
	return (NULL);
      if (access(bin_tmp, F_OK) == 0)
	return (bin_tmp);
      tmp = tmp->next;
    }
  return (bin);
}

char		*get_bin_path(char *bin, char **envp)
{
  int		i;
  t_bin		*list_bin;

  i = 0;
  if ((i = get_var_bin(envp)) == -1)
    return (NULL);
  if ((list_bin = make_bin()) == NULL)
    return (NULL);
  if (str_to_pathslist(list_bin, envp[i]) == -1)
    return (NULL);
  return (path_bin(bin, list_bin));
}
