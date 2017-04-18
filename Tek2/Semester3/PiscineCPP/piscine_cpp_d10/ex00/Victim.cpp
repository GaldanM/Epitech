#include "Victim.hh"

/* INIT */
Victim::Victim(std::string const &name) : _name(name)
{
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &to_copy) : _name(to_copy._name)
{
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim()
{
		std::cout << "Victim " <<_name << " just died for no apparent reason !" << std::endl;
}
/* GETTERS */
std::string Victim::getName() const
{
  return (_name);
}

/* OTHERS */
void        Victim::getPolymorphed() const
{
  std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

/* OPERATORS */
Victim&	Victim::operator=(Victim const &to_copy)
{
  if (&to_copy)
    {
      if (_name != to_copy._name)
      	_name = to_copy._name;
    }
  return (*this);
}

std::ostream&	operator<<(std::ostream& os, Victim const &antoine)
{
  os << "I'm " << antoine.getName() << " and i like otters !" << std::endl;
  return (os);
}