#ifndef LEMON_H_
# define LEMON_H_

# include "Fruit.h"

class Lemon : public Fruit
{
public:
	Lemon();
	virtual ~Lemon();

	std::string	getName() const;
};

#endif