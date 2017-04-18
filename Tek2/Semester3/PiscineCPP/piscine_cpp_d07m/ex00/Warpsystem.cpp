//
// Warpsystem.cpp for warp in /home/moulin_c/rendu
// 
// Made by Galdan MOULINNEUF
// Login   <moulin_c@epitech.net>
// 
// Started on  Tue Jan 13 12:32:29 2015 Galdan MOULINNEUF
// Last update Wed Jan 14 00:12:26 2015 Galdan MOULINNEUF
//

#include	"Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor(bool _stab)
{
  this->_stability = _stab;
}

bool		WarpSystem::QuantumReactor::isStable()
{
  return (this->_stability);
}

void		WarpSystem::QuantumReactor::setStability(bool stab)
{
  this->_stability = stab;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{

}

WarpSystem::Core::Core(QuantumReactor *ptr)
{
  this->_coreReactor = ptr;
}


WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
  return (this->_coreReactor);
}

WarpSystem::Core::~Core()
{

}
