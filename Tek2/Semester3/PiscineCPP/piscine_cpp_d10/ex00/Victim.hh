#ifndef VICTIM_H_
# define VICTIM_H_

# include <iostream>
# include <string>

class Victim
{
protected:
	std::string	_name;

public:
	/* INIT */
	Victim(std::string const &);
	Victim(Victim const &);
	virtual ~Victim();

	/* GETTERS */
	std::string	getName() const;

	/* OTHERS */
	virtual void getPolymorphed() const;
	
	/* OPERATORS */
	Victim&	operator=(Victim const &to_copy);
};

std::ostream&	operator<<(std::ostream& os, Victim const &);

#endif /* !VICTIM_H_ */