#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"elcrypt.h"

int		set_fds(char **argv, int i, char opt)
{
  int		fd;

  if ((fd = open_file(argv[i + 1], opt)) == -1)
    {
      printf("Can't open file : \"%s\".\n", argv[i + 1]);
      return (-1);
    }
  return (fd);
}

int		set_param_pointers(char **argv, t_param *p, int *i)
{
  if (!strcmp(argv[*i], "-f") && argv[*i + 1])
    {
      if ((p->f = set_fds(argv, *i, 0)) == -1)
	return (-1);
    }
  else if (!strcmp(argv[*i], "-o") && argv[*i + 1])
    {
      if ((p->o = set_fds(argv, *i, 1)) == -1)
	return (-1);
    }
  else if (!strcmp(argv[*i], "-k") && argv[*i + 1])
    p->k = strtoul(argv[*i + 1], NULL, 10);
  else if (!argv[*i + 1])
    {
      printf("%s need a parameter !\n", argv[*i]);
      return (-1);
    }
  else
    {
      printf("%s is not recognized\n", argv[*i]);
      return (-1);
    }
  ++(*i);
  return (0);
}

int		set_param(char **argv, t_param *p)
{
  int		i;

  i = 1;
  while (argv[i])
    {
      if (!strcmp(argv[i], "-d"))
	p->d = 1;
      else if (!strcmp(argv[i], "-e"))
	p->e = 1;
      else
        if (set_param_pointers(argv, p, &i) == -1)
          return (-1);
      ++i;
    }
  if (check_param(p) == -1)
    return (-1);
  return (0);
}
