#ifndef WOODY_H_
# define WOODY_H_

# include "Toy.h"

class Woody : public Toy
{
public:
	Woody(std::string const&, std::string const &file = "woody.txt");
	virtual ~Woody();
	
	virtual void		speak(std::string const&);
};

#endif