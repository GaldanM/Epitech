//
// koaladoctorlist.cpp for doctor in /home/moulin_c/rendu/piscine_cpp_d06/ex05
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 09:47:36 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 09:47:59 2015 Galdan MOULINNEUF
//

#include <cstdlib>
#include "koaladoctorlist.h"
#include "koaladoctor.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *patient)
{
  this->patient = patient;
  this->next = NULL;
}

bool		KoalaDoctorList::isEnd()
{
  if (this->next)
    return (false);
  return (true);
}

void		KoalaDoctorList::append(KoalaDoctorList *next)
{
  if (!this->isEnd())
    this->next->append(next);
  else
    this->next = next;
}

KoalaDoctor	*KoalaDoctorList::getFromName(std::string name)
{
  if (!this->next)
    return (this->next->getFromName(name));
  else if (this->patient && name == this->patient->getName())
    return (this->patient);
  else
    return (NULL);
  return (NULL);
}

KoalaDoctorList*	KoalaDoctorList::remove(KoalaDoctorList* del)
{
  KoalaDoctorList *actual;
  KoalaDoctorList *prec;

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

KoalaDoctorList	*KoalaDoctorList::removeFromName(std::string elem)
{
  KoalaDoctorList *actual;
  KoalaDoctorList *prec;

  actual = this;
  prec = NULL;
  while (actual)
    {
      if (actual && actual->patient)
	{
	  if (elem == actual->patient->getName())
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

void		KoalaDoctorList::dump()
{
  KoalaDoctorList	*actual;
  std::string	list("Liste des patients : ");

  actual = this;
  std::cout << list;
  while (NULL != actual)
    {
      if (actual->patient == NULL)
	std::cout << "NULL";
      else
	std::cout << actual->patient->getName();
      if (NULL != actual->next)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
      actual = actual->next;
    }
}

KoalaDoctor	*KoalaDoctorList::getContent()
{
  return (this->patient);
}

KoalaDoctorList*	KoalaDoctorList::getNext()
{
  if (!this->next)
    return (NULL);
  return (this->next);
}

KoalaDoctorList::~KoalaDoctorList()
{

}
