#ifndef  BUZZ_H_
# define BUZZ_H_

# include "Toy.h"

class Buzz : public Toy
{
public:
	Buzz(std::string const&, std::string const &file = "buzz.txt");
	~Buzz();

};

#endif
