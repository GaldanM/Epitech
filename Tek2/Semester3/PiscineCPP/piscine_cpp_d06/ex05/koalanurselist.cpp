//
// sickkoalalist.cpp for list in /home/moulin_c/rendu/piscine_cpp_d06/ex05
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 09:13:39 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 09:45:27 2015 Galdan MOULINNEUF
//

#include <cstdlib>
#include "koalanurselist.h"
#include "koalanurse.h"
#include "sickkoala.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *patient)
{
  this->patient = patient;
  this->next = NULL;
}

bool		KoalaNurseList::isEnd()
{
  if (this->next)
    return (false);
  else
    return (true);
  return (true);
}

void		KoalaNurseList::append(KoalaNurseList *next)
{
  if (!this->isEnd())
    this->next->append(next);
  else
    this->next = next;
}

KoalaNurse	*KoalaNurseList::getFromID(int name)
{
  if (!this->next)
    return (this->next->getFromID(name));
  else if (this->patient && name == this->patient->getID())
    return (this->patient);
  else
    return (NULL);
  return (NULL);
}

KoalaNurseList*	KoalaNurseList::remove(KoalaNurseList* del)
{
  KoalaNurseList *actual;
  KoalaNurseList *prec;

  actual = this;
  prec = NULL;
  while (actual)
    {
      if (actual == del)
	{
	  if (prec)
	    {
	      prec->next = actual->next;
	      actual->next = NULL;
	      return (this);
	    }
	  else
	    {
	      prec = actual->next;
	      actual->next = NULL;
	      return (prec);
	    }
	}
      prec = actual;
      actual = actual->next;
    }
  return (NULL);
}

KoalaNurseList	*KoalaNurseList::removeFromID(int elem)
{
  KoalaNurseList *actual;
  KoalaNurseList *prec;

  actual = this;
  prec = NULL;
  while (actual)
    {
      if (actual && actual->patient)
	{
	  if (elem == actual->patient->getID())
	    {
	      if (prec)
		{
		  prec->next = actual->next;
		  actual->next = NULL;
		  return (this);
		}
	      else
		{
		  prec = actual->next;
		  actual->next = NULL;
		  return (prec);
		}
	    }
	}
      prec = actual;
      actual = actual->next;
    }
  return (NULL);
}

void		KoalaNurseList::dump()
{
  KoalaNurseList	*actual;
  std::string	list("Liste des patients : ");

  actual = this;
  std::cout << list;
  while (NULL != actual)
    {
      if (actual->patient == NULL)
	std::cout << "NULL";
      else
	std::cout << actual->patient->getID();
      if (NULL != actual->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      actual = actual->next;
    }
}

KoalaNurse	*KoalaNurseList::getContent()
{
  return (this->patient);
}

KoalaNurseList*	KoalaNurseList::getNext()
{
  if (!this->next)
    return (NULL);
  return (this->next);
}

KoalaNurseList::~KoalaNurseList()
{

}
