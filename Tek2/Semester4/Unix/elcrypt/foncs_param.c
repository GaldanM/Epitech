#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"elcrypt.h"

void		init_param(t_param *p)
{
  p->d = 0;
  p->e = 0;
  p->f = 0;
  p->o = 1;
  p->k = 0;
}

int		open_file(char *file, char opt)
{
  int		fd;
  int		flags;

  if (!opt)
    {
      if ((fd = open(file, O_RDONLY)) == -1)
	return (-1);
    }
  else
    {
      flags = S_IWUSR | S_IRGRP | S_IRUSR | S_IROTH;
      if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, flags)) == -1)
	return (-1);
    }
  return (fd);
}

int		check_param(t_param *p)
{
  if (p->e && p->d)
    {
      printf("You can't decypt and encrypt...\n");
      return (-1);
    }
  if (!p->e && !p->d)
    {
      printf("You have to choose between decypt and encrypt !\n");
      return (-1);
    }
  if (!p->f || !p->k)
    {
      printf("You have to put a source file AND a key !\n");
      return (-1);
    }
  return (0);
}
