/*
** main.c for fonc_philo in /home/ounajj_k/rendu/PSU_2014_philo
** 
** Made by Khaled Ounajjar
** Login   <ounajj_k@epitech.net>
** 
** Started on  Sun Mar  1 20:25:55 2015 Khaled Ounajjar
** Last update Sun Mar  1 22:53:24 2015 Galdan MOULINNEUF
*/

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "philo.h"

extern pthread_mutex_t	mut;
extern t_ph		g_philo[PHILO];
extern int		g_stick[PHILO];

void			*eating(t_ph *phi)
{
  g_stick[phi->pos] = 1;
  g_stick[(phi->pos + 1) % PHILO] = 1;
  pthread_mutex_unlock(&mut);
  phi->status = EAT;
  phi->rice -= 10;
  printf("PH: %d is eating\n", phi->pos);
  sleep(TIME);
  if (phi->rice <= 0)
    {
      phi->quit = 0;
      printf("PH: %d leave the table\n", phi->pos);
    }
  if (phi->quit != 0)
    printf("PH: %d finished eating\n", phi->pos);
  pthread_mutex_lock(&mut);
  g_stick[phi->pos] = 0;
  g_stick[(phi->pos + 1) % PHILO] = 0;
  pthread_mutex_unlock(&mut);
  return (NULL);
}

void			*thinking(t_ph *phi)
{
  g_stick[phi->pos] = 1;
  phi->status = THK;
  pthread_mutex_unlock(&mut);
  printf("PH: %d is thinking\n", phi->pos);
  sleep(TIME);
  printf("PH: %d finished thinking\n", phi->pos);
  while (phi->status != EAT)
    {
      pthread_mutex_lock(&mut);
      if (g_stick[(phi->pos + 1) % PHILO] == 0)
  	eating(phi);
      else
  	pthread_mutex_unlock(&mut);
    }
  return (NULL);
}

void			*sleeping(t_ph *phi)
{
  pthread_mutex_unlock(&mut);
  if (phi->status == SLEEP)
    return (NULL);
  phi->status = SLEEP;
  printf("PH: %d is sleeping\n", phi->pos);
  sleep(TIME);
  printf("PH: %d is waking up\n", phi->pos);
  return (NULL);
}

void			*exec_status(void *v_phil)
{
  t_ph			*phi;
  int			stick;
  int			stick_next;

  phi = (t_ph *)v_phil;
  while (phi->quit && phi->rice >= 0)
    {
      pthread_mutex_lock(&mut);
      stick = g_stick[phi->pos];
      stick_next = g_stick[(phi->pos + 1) % PHILO];
      if (phi->status != EAT && stick == 0 && stick_next == 0)
	eating(phi);
      else if (phi->status != THK && phi->status != EAT && stick == 0)
	thinking(phi);
      else
	sleeping(phi);
    }
  return (NULL);
}
