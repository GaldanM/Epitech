/*
** parser.c for parser in /home/moulin_c/rendu/colle3_moulin_c_OaHTo/srcs
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon May 12 19:49:57 2014 moulin_c
** Last update Mon May 12 20:34:01 2014 moulin_c
*/

#include	<stdlib.h>
#include	"lists.h"

#define		TITLE(str) (!strncmp(str, "<title>", 7))
#define		URL(str) (!strncmp(str, "<link>", 6))
#define		DESC(str) (!strncmp(str, "<description>", 13))

void		init_param(t_items *param)
{
  param = malloc(sizeof(param));
  param->title = NULL;
  param->link = NULL;
  param->desc = NULL;
}

void		parser(t_file **tabl, int i, char *file)
{
  t_items	param;
  char		*str;
  int		fd;

  fd = open(file);
  tabl[i]->list_items = make_items();
  init_param(&param);
  while ((str = my_read_line(fd)))
    {
      if (TITLE(str))
	param.title = str;
      else if (URL(str))
	param.link = str;
      else if (DESC(str))
	param.desc = str;
      if (param.title && param.link && param.desc)
	{
	  printf("title = '%s'\tlink = '%s'\tdesc = '%s'\n", param.title, param.link, param.desc);
	  exit(1);
	  add_item(&tabl[i]->list_items, &param);
	  init_param(&param);
	}
    }
}

int		main(int argc, char **argv)
{
  t_file	*tabl;
  int		i;

  i = 1;
  tabl = malloc(sizeof(tabl) * (argc));
  while (argv[i])
    {
      parser(&tabl, i - 1, argv[i]);
      i++;
    }
  tabl[i].file_name = NULL;
}
