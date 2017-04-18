//
// droidmemory.cpp for droidmem in /home/moulin_c/rendu/piscine_cpp_d08/ex01
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Wed Jan 14 19:27:10 2015 Galdan MOULINNEUF
// Last update Thu Jan 15 07:49:39 2015 Galdan MOULINNEUF
//

#include	<cstdlib>
#include	<iostream>
#include	<string>
#include	<cstdio>
#include	"droidmemory.hh"

/* INIT */
DroidMemory::DroidMemory() : _Exp(0)
{
  this->_FingerPrint = random();
}

DroidMemory::DroidMemory(DroidMemory const &to_copy) : _Exp(to_copy._Exp), _FingerPrint(to_copy._FingerPrint)
{

}

DroidMemory::~DroidMemory()
{

}

/* GETTERS */
size_t		DroidMemory::getFingerPrint() const
{
  return (this->_FingerPrint);
}

size_t		DroidMemory::getExp() const
{
  return (this->_Exp);
}

/* SETTERS */
void		DroidMemory::setFingerPrint(size_t FP)
{
  this->_FingerPrint = FP;
}

void		DroidMemory::setExp(size_t XP)
{
  this->_Exp = XP;
}

/* OPERATORS */
DroidMemory&	DroidMemory::operator=(DroidMemory const &to_copy)
{
  if (&to_copy)
    if (this != &to_copy)
      {
	this->_FingerPrint = to_copy._FingerPrint;
	this->_Exp = to_copy._Exp;
      }
  return (*this);
}

DroidMemory&	DroidMemory::operator<<(DroidMemory const &to_add)
{
  this->_Exp = this->_Exp + to_add._Exp;
  this->_FingerPrint = this->_FingerPrint^to_add._FingerPrint;
  return (*this);
}

DroidMemory&	DroidMemory::operator>>(DroidMemory& to_add)
{
  to_add._Exp = to_add._Exp + this->_Exp;
  to_add._FingerPrint = to_add._FingerPrint^this->_FingerPrint;
  return (to_add);
}

DroidMemory&	DroidMemory::operator+=(DroidMemory const &to_comp)
{
  this->_Exp = this->_Exp + to_comp._Exp;
  this->_FingerPrint = this->_FingerPrint^to_comp._FingerPrint;
  return (*this);
}

DroidMemory&	DroidMemory::operator+=(size_t add)
{
  this->_Exp = this->_Exp + add;
  this->_FingerPrint = this->_FingerPrint^add;
  return (*this);
}

DroidMemory&	DroidMemory::operator+(DroidMemory const &to_comp)
{
  DroidMemory	*elem = new DroidMemory();

  this->_Exp = this->_Exp + to_comp._Exp;
  this->_FingerPrint = this->_FingerPrint^to_comp._Exp;
  elem = this;
  return (*elem);
}

DroidMemory&	DroidMemory::operator+(size_t add)
{
  DroidMemory	*elem = new DroidMemory();

  this->_Exp = this->_Exp + add;
  this->_FingerPrint = this->_FingerPrint^add;
  elem = this;
  return (*elem);
}

std::ostream&	operator<<(std::ostream& os, DroidMemory const &xperia)
{
  os << "DroidMemory '" << xperia.getFingerPrint() << "', " << xperia.getExp();

  return (os);
}
