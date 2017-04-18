#include "Peon.hh"

/* INIT */
Peon::Peon(std::string const &name) : Victim(name)
{
  std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &to_copy) : Victim(to_copy)
{
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

/* OTHERS */
void        Peon::getPolymorphed() const
{
  std::cout << _name << " has been turned into a pink pony !" << std::endl;
}

/* OPERATORS */
Peon&	Peon::operator=(Peon const &to_copy)
{
  if (&to_copy)
    {
      if (_name != to_copy._name)
      {
      	_name = to_copy._name;
      }
 }
  return (*this);
}

std::ostream&	operator<<(std::ostream& os, Peon const &antoine)
{
  os << "I'm " << antoine.getName() << " and i like otters !" << std::endl;
  return (os);
}