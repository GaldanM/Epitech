/*
** init_philo.c for init philo in /home/ounajj_k/rendu/PSU_2014_philo
** 
** Made by Khaled Ounajjar
** Login   <ounajj_k@epitech.net>
** 
** Started on  Sun Mar  1 20:26:22 2015 Khaled Ounajjar
** Last update Sun Mar  1 22:55:18 2015 Galdan MOULINNEUF
*/

#include	"philo.h"

extern t_ph	g_philo[PHILO];
extern int	g_stick[PHILO];

void		init_stick()
{
  int		i;

  i = 0;
  while (i < PHILO)
    {
      g_stick[i] = 0;
      ++i;
    }
}

void		init_philo()
{
  int		i;

  i = 0;
  init_stick();
  while (i < PHILO)
    {
      g_philo[i].pos = i;
      g_philo[i].quit = 1;
      g_philo[i].status = 0;
      g_philo[i].rice = RICE;
      pthread_create(&g_philo[i].threads, NULL, exec_status, &g_philo[i]);
      i++;
    }
}
