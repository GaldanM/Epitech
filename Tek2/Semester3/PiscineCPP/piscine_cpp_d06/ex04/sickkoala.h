/*
** sickkoala.h for sickkoala in /home/moulin_c/rendu/piscine_cpp_d06/ex02
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Mon Jan 12 13:41:11 2015 Galdan MOULINNEUF
** Last update Mon Jan 12 19:10:12 2015 Galdan MOULINNEUF
*/

#ifndef SICKKOALA_H_
# define SICKKOALA_H_

# include	<iostream>

class		SickKoala
{
  std::string	name;

 public:
  SickKoala(std::string);
  void		poke(void);
  bool		takeDrug(std::string);
  void		overDrive(std::string);
  std::string	getName();
  ~SickKoala();
};

#endif /* !SICKOALA_H_ */
