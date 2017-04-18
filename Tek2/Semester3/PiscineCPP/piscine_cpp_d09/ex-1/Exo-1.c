/*
** Exo-1.c for cthulhu in /home/moulin_c/rendu/piscine_cpp_d09/ex-1
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan 15 10:39:20 2015 Galdan MOULINNEUF
** Last update Thu Jan 15 11:46:33 2015 Galdan MOULINNEUF
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"Exo-1.h"

static void	CthulhuInitializer(t_cthulhu *this);
static void	KoalaInitializer(t_koala *this, char *_name, char _isALegend);

t_cthulhu	*NewCthulhu()
{
  t_cthulhu	*new;

  printf("----\n");
  if ((new = malloc(sizeof(t_cthulhu))) == NULL)
    return (NULL);
  CthulhuInitializer(new);
  return (new);
}

static void	CthulhuInitializer(t_cthulhu *this)
{
  printf("Building Cthulhu\n");
  this->m_name = strdup("Cthulhu");
  this->m_power = 42;
}

void		PrintPower(t_cthulhu *this)
{
  printf("Power => %d\n", this->m_power);
}

void		Attack(t_cthulhu *this)
{
  if (this->m_power >= 42)
    {
      printf("%s attacks and destroys the city\n", this->m_name);
      this->m_power -= 42;
    }
  else
    printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void		Sleeping(t_cthulhu *this)
{
  printf("%s sleeps\n", this->m_name);
  this->m_power += 42000;
}

/* KOALA */

t_koala		*NewKoala(char *name, char _isALegend)
{
  t_koala	*new;

  printf("----\n");
  if ((new = malloc(sizeof(t_koala))) == NULL)
    return (NULL);
  KoalaInitializer(new, name, _isALegend);
  return (new);
}

static void	KoalaInitializer(t_koala *this, char *_name, char _isALegend)
{
  CthulhuInitializer(&this->m_parent);
  printf("Building %s\n", _name);
  this->m_parent.m_name = _name;
  this->m_isALegend = _isALegend;
  if (!this->m_isALegend)
    this->m_parent.m_power = 0;
}

void		Eat(t_koala *this)
{
  printf("%s eats\n", this->m_parent.m_name);
  this->m_parent.m_power += 42;
}
