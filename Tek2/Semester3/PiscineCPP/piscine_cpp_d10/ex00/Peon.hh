#ifndef PEON_H_
# define PEON_H_

# include "Victim.hh"

class Peon : public Victim
{
public:
	/* INIT */
	Peon(std::string const &);
	Peon(Peon const &);
	virtual ~Peon();

	/* GETTERS */

	/* OTHERS */
	virtual void getPolymorphed() const;
	/* OPERATORS */
	Peon&	operator=(Peon const &to_copy);
};

std::ostream&	operator<<(std::ostream& os, Peon const &);

#endif /* !PEON_H_ */