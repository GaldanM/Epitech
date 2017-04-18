#ifndef COCONUT_H_
# define COCONUT_H_

#include "Fruit.h"

class Coconut : public Fruit
{
public:
	Coconut();
	virtual ~Coconut();
	
	virtual std::string	getName() const;
};

#endif