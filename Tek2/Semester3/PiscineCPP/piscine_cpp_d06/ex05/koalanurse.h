/*
** koalanurse.h for koalanurse in /home/moulin_c/rendu/piscine_cpp_d06/ex02
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan 12 16:48:11 2015 Galdan MOULINNEUF
** Last update Tue Jan 13 09:45:13 2015 Galdan MOULINNEUF
*/

#ifndef KOALANURSE_H_
# define KOALANURSE_H_

# include	<iostream>
# include	<fstream>
# include	"sickkoala.h"

class		KoalaNurse
{
  int		id;
  bool		working;

 public:
  KoalaNurse(int);
  void		giveDrug(std::string, SickKoala *);
  std::string	readReport(std::string);
  int		getID();
  void		timeCheck();
  ~KoalaNurse();
};

#endif /* !KOALANURSE_H_ */
