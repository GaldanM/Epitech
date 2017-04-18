#include "Sorcerer.hh"

/* INIT */
Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &to_copy) : _name(to_copy._name), _title(to_copy._title)
{
	std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
		std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

/* GETTERS */
std::string	Sorcerer::getName() const
{
	return (_name);
}

std::string	Sorcerer::getTitle() const
{
	return (_title);
}

/* OTHERS */
void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

/* OPERATORS */
Sorcerer&	Sorcerer::operator=(Sorcerer const &to_copy)
{
  if (&to_copy)
    {
      if (_name != to_copy._name || _title != to_copy._title)
      {
      	_name = to_copy._name;
      	_title = to_copy._title;
      }
 }
  return (*this);
}

std::ostream&	operator<<(std::ostream& os, Sorcerer const &merlin)
{
  os << "I am " << merlin.getName() << ", " << merlin.getTitle() << ", and I like ponies !" << std::endl;
  return (os);
}