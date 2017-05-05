/*
** main.c for main in /home/ounajj_k/rendu/PSU_2014_philo
** 
** Made by Khaled Ounajjar
** Login   <ounajj_k@epitech.net>
** 
** Started on  Sun Mar  1 20:48:05 2015 Khaled Ounajjar
** Last update Sun Mar  1 22:54:07 2015 Galdan MOULINNEUF
*/

#include "philo.h"

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
t_ph		g_philo[PHILO];
int		g_stick[PHILO];

void		start_action()
{
  int		i;

  i = 0;
  while (i < PHILO)
    {
      pthread_join(g_philo[i].threads, NULL);
      i++;
    }
}

int		main()
{
  init_philo();
  start_action();
  return (0);
}
