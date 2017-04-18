/*
** sickkoalalist.h for list in /home/moulin_c/rendu/piscine_cpp_d06/ex05
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Jan 13 09:13:54 2015 Galdan MOULINNEUF
** Last update Tue Jan 13 09:15:38 2015 Galdan MOULINNEUF
*/

#ifndef SICKKOALALIST_H_
# define SICKKOALALIST_H_

#include <iostream>
#include "sickkoala.h"

class	SickKoalaList
{
  SickKoala *patient;
  SickKoalaList	*next;

 public:
  SickKoalaList(SickKoala *);
  bool	isEnd();
  void	append(SickKoalaList *);
  SickKoala* getFromName(std::string);
  SickKoalaList* remove(SickKoalaList*);
  SickKoalaList* removeFromName(std::string);
  void	dump();
  SickKoalaList* getNext();
  SickKoala* getContent();
  ~SickKoalaList();
};

#endif /* !SICKKOALALIST_H_ */
