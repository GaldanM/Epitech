/*
** koaladoctorlist.h for koaladoctorlist in /home/moulin_c/rendu/piscine_cpp_d06/ex05
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Jan 13 09:46:43 2015 Galdan MOULINNEUF
** Last update Tue Jan 13 09:47:21 2015 Galdan MOULINNEUF
*/

#ifndef KOALADOCTORLIST_H_
# define  KOALADOCTORLIST_H_

#include <iostream>
#include "koaladoctor.h"

class	KoalaDoctorList
{
  KoalaDoctor *patient;
  KoalaDoctorList	*next;

 public:
  KoalaDoctorList(KoalaDoctor *);
  bool	isEnd();
  void	append(KoalaDoctorList *);
  KoalaDoctor* getFromName(std::string);
  KoalaDoctorList* remove(KoalaDoctorList*);
  KoalaDoctorList* removeFromName(std::string);
  void	dump();
  KoalaDoctorList* getNext();
  KoalaDoctor* getContent();
  ~KoalaDoctorList();
};

#endif /* !KOALADOCTORLIST_H_ */
