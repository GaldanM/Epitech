//
// sickkoalalist.cpp for list in /home/moulin_c/rendu/piscine_cpp_d06/ex05
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 09:13:39 2015 Galdan MOULINNEUF
// Last update Tue Jan 13 09:35:58 2015 Galdan MOULINNEUF
//

#include <cstdlib>
#include "sickkoalalist.h"
#include "sickkoala.h"

SickKoalaList::SickKoalaList(SickKoala *patient)
{
  this->patient = patient;
  this->next = NULL;
}

bool		SickKoalaList::isEnd()
{
  if (this->next)
    return (false);
  return (true);
}

void		SickKoalaList::append(SickKoalaList *next)
{
  if (!this->isEnd())
    this->next->append(next);
  else
    this->next = next;
}

SickKoala	*SickKoalaList::getFromName(std::string name)
{
  if (!this->next)
    return (this->next->getFromName(name));
  else if (this->patient && name == this->patient->getName())
    return (this->patient);
  else
    return (NULL);
  return (NULL);
}

SickKoalaList*	SickKoalaList::remove(SickKoalaList* del)
{
  SickKoalaList *actual;
  SickKoalaList *prec;

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

SickKoalaList	*SickKoalaList::removeFromName(std::string elem)
{
  SickKoalaList *actual;
  SickKoalaList *prec;

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

void		SickKoalaList::dump()
{
  SickKoalaList	*actual;
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

SickKoala	*SickKoalaList::getContent()
{
  return (this->patient);
}

SickKoalaList*	SickKoalaList::getNext()
{
  if (!this->next)
    return (NULL);
  return (this->next);
}

SickKoalaList::~SickKoalaList()
{

}
