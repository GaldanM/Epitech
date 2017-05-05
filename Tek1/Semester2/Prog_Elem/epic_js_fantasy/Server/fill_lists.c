/*
** fill_lists.c for fill_lists in /home/moulin_c/rendu/epic_js_fantasy/Server
** 
** Made by moulin_c
** Login   <moulin_c@epitech.net>
** 
** Started on  Sat May 10 19:10:20 2014 moulin_c
** Last update Sun May 11 20:32:48 2014 moulin_c
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"fantasy.h"

char		*recup_str(int *i, char *line)
{
  char		*str;
  int		len;
  int		j;
  int		save;

  j = 0;
  while (line[*i] <= 32)
    (*i)++;
  len = 1;
  save = *i;
  while (line[save] > 32)
    {
      len++;
      save++;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    my_exitstr("Malloc failed");
  while (line[*i] > 32)
    str[j++] = line[(*i)++];
  str[j] = '\0';
  return (str);
}

void		fill_header(t_header *header, char *line, int i)
{
  while (line[i])
    {
      if (line[i] == 1)
	header->name = recup_str(&i, line);
      else if (line[i] == 2)
	header->end = recup_str(&i, line);
      else if (line[i] == 3)
	header->start = recup_str(&i, line);
      else
	my_exitstr("Wrong file");
    }
  if (!header->end || !header->start)
    my_exitstr("Wrong header [end-start]");
}

/*
**printf("HEADER :\nname = '%s'\tend = '%s'\tstart = '%s'\n\n\n",
**header->name, header->end, header->start);
*/

void		fill_champ(t_header *header, char *line, int i)
{
  t_champs	*champ;

  if ((champ = malloc(sizeof(*champ))) == NULL)
    my_exitstr("Malloc failed");
  champ->name = NULL;
  while (line[i])
    {
      if (line[i] == 1)
	champ->name = recup_str(&i, line);
      else if (line[i] == 4)
	champ->type = recup_str(&i, line);
      else if (line[i] == 8)
	champ->weapon = recup_str(&i, line);
      else if (line[i] == 9)
	champ->armor = recup_str(&i, line);
      else if (line[i] == 20 || line[i] == 32)
	champ->spe = atoi(recup_str(&i, line));
      else if (line[i] == 6)
	champ->spd = atoi(recup_str(&i, line));
      else if (line[i] == 7)
	champ->deg = atoi(recup_str(&i, line));
      else if (line[i] == 5)
	champ->hp = atoi(recup_str(&i, line));
      else
	my_exitstr("Wrong file");
    }
  add_champ(&(header->list_champs), champ);
}

/*
**printf("CHAMP :\nname = '%s'\ntype = '%s'\nweapon = '%s'\narmor = '%s'\nhp = %d\nspe = %d\nspd = %d\ndeg = %d\n\n\n",
**header->list_champs->prev->name, header->list_champs->prev->type,
**header->list_champs->prev->weapon, header->list_champs->prev->armor,
**header->list_champs->prev->hp, header->list_champs->prev->spe,
**header->list_champs->prev->spd, header->list_champs->prev->deg);
*/

void		fill_monster(t_header *header, char *line, int i)
{
  t_monsts	*monst;

  if ((monst = malloc(sizeof(*monst))) == NULL)
    my_exitstr("Malloc failed");
  while (line[i])
    {
      if (line[i] == 4)
	monst->type = recup_str(&i, line);
      else if (line[i] == 8)
	monst->weapon = recup_str(&i, line);
      else if (line[i] == 9)
	monst->armor = recup_str(&i, line);
      else if (line[i] == 5)
	monst->hp = atoi(recup_str(&i, line));
      else if (line[i] == 20 || line[i] == 32)
	monst->spe = atoi(recup_str(&i, line));
      else if (line[i] == 6)
	monst->spd = atoi(recup_str(&i, line));
      else if (line[i] == 7)
	monst->deg = atoi(recup_str(&i, line));
      else
	my_exitstr("Wrong file");
    }
  add_monst(&(header->list_monsts), monst);
}

/*
**printf("MONSTER :\ntype = '%s'\nweapon = '%s'\narmor = '%s'\nhp = %d\nspe = %d\nspd = %d\ndeg = %d\n\n\n",
**header->list_monsts->prev->type, header->list_monsts->prev->weapon,
**header->list_monsts->prev->armor, header->list_monsts->prev->hp,
**header->list_monsts->prev->spe, header->list_monsts->prev->spd,
**header->list_monsts->prev->deg);
*/

void		fill_room(t_header *header, char *line, int i)
{
  t_rooms	*room;

  if ((room = malloc(sizeof(*room))) == NULL)
    my_exitstr("Malloc failed");
  while (line[i])
    {
      if (line[i] == 1)
	room->name = recup_str(&i, line);
      else if (line[i] == 16)
	room->adv = atoi(recup_str(&i, line));
      else if (line[i] == 17)
	room->connect = recup_str(&i, line);
      else if (line[i] == 18)
	room->monster = recup_str(&i, line);
      else
	my_exitstr("Wrong file");
    }
  add_room(&(header->list_rooms), room);
}

/*
**printf("SALLE :\nname = '%s'\nadv = '%d'\nconnect = '%s'\nmonst = %s\n\n\n",
**header->list_rooms->prev->name, header->list_rooms->prev->adv,
**header->list_rooms->prev->connect, header->list_rooms->prev->monster);
*/
