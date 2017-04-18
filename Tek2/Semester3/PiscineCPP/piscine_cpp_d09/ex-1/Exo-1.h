/*
** Exo-1.h for cthulhu in /home/moulin_c/rendu/piscine_cpp_d09/ex-1
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Thu Jan 15 10:37:24 2015 Galdan MOULINNEUF
** Last update Thu Jan 15 11:32:34 2015 Galdan MOULINNEUF
*/

#ifndef EXO_1_H_
# define EXO_1_H_

typedef struct	s_cthulhu
{
  int		m_power;
  char		*m_name;
}		t_cthulhu;

t_cthulhu	*NewCthulhu();
void		PrintPower(t_cthulhu *this);
void		Attack(t_cthulhu *this);
void		Sleeping(t_cthulhu *this);

typedef struct	s_koala
{
  t_cthulhu	m_parent;
  char		m_isALegend;
}		t_koala;

t_koala		*NewKoala(char *name, char _isALegend);
void		Eat(t_koala *);

#endif /* EXO_1_H */
