/*
** koaladoctor.h for koaladoctor in /home/moulin_c/rendu/piscine_cpp_d06/ex04
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan 12 19:12:09 2015 Galdan MOULINNEUF
** Last update Tue Jan 13 09:48:54 2015 Galdan MOULINNEUF
*/

#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

# include "sickkoala.h"

class	KoalaDoctor
{
  std::string	name;
  bool		working;

 public:
  KoalaDoctor(std::string);
  void	diagnose(SickKoala *);
  void	timeCheck(void);
  std::string	getName();
  ~KoalaDoctor();
};

#endif /* !KOALADOCTOR */
