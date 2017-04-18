#ifndef SORCERER_H_
# define SORCERER_H_

# include <iostream>
# include <string>
# include "Victim.hh"

class Sorcerer
{
protected:
	std::string	_name;
	std::string	_title;

public:
	/* INIT */
	Sorcerer(std::string, std::string);
	Sorcerer(Sorcerer const &);
	~Sorcerer();

	/* GETTERS */
	std::string	getName() const;
	std::string	getTitle() const;

	/* OTHERS */
	void polymorph(Victim const &) const;

	/* OPERATORS */
	Sorcerer&	operator=(Sorcerer const &to_copy);
};

std::ostream&	operator<<(std::ostream& os, Sorcerer const &);

#endif /* !SORCERER_H_ */