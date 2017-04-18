/*
** sickkoalalist.h for list in /home/moulin_c/rendu/piscine_cpp_d06/ex05
** 
** Made by Galdan MOULINNEUF
** Login   <moulin_c@epitech.net>
** 
** Started on  Tue Jan 13 09:13:54 2015 Galdan MOULINNEUF
** Last update Tue Jan 13 09:43:52 2015 Galdan MOULINNEUF
*/

#ifndef KOALANURSELIST_H_
# define KOALANURSELIST_H_

#include <iostream>
#include "koalanurse.h"
 
class	KoalaNurseList
{
  KoalaNurse *patient;
  KoalaNurseList	*next;

 public:
  KoalaNurseList(KoalaNurse *);
  bool	isEnd();
  void	append(KoalaNurseList *);
  KoalaNurse* getFromID(int);
  KoalaNurseList* remove(KoalaNurseList*);
  KoalaNurseList* removeFromID(int);
  void	dump();
  KoalaNurseList* getNext();
  KoalaNurse* getContent();
  ~KoalaNurseList();
};

#endif /* !KOALANURSELIST_H_ */
