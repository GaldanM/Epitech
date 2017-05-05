/*
** philo.h for philo h in /home/ounajj_k/rendu/PSU_2014_philo
** 
** Made by Khaled Ounajjar
** Login   <ounajj_k@epitech.net>
** 
** Started on  Sun Mar  1 20:56:28 2015 Khaled Ounajjar
** Last update Sun Mar  1 22:54:45 2015 Galdan MOULINNEUF
*/

#ifndef PHILO_H_
# define PHILO_H_

# define THK 1
# define EAT 2
# define SLEEP 3
# define PHILO 7
# define RICE 40
# define TIME 1

# include	<pthread.h>

typedef struct	s_philosophers
{
  pthread_t	threads;
  int		pos;
  int		quit;
  int		status;
  int		rice;
}		t_ph;

void		init_stick();
void		init_philo();

void		*eating(t_ph*);
void		*thinking(t_ph*);
void		*sleeping(t_ph*);
void		*exec_status(void*);

void		start_action();

#endif /* !PHILO_H_ */
