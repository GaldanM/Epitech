#ifndef  BUZZ_H_
# define BUZZ_H_

# include "Toy.h"

class Buzz : public Toy
{
public:
	Buzz(std::string const&, std::string const &file = "buzz.txt");
	virtual ~Buzz();
	
	virtual void		speak(std::string const&);
	virtual bool		speak_es(std::string const&);
};

#endif