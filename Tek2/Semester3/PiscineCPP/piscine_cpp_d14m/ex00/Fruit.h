#ifndef FRUIT_H_
# define FRUIT_H_

# include <iostream>

class Fruit
{
protected:
	std::string _name;
	int			_vitamins;

	
public:
	Fruit(std::string, int);
	virtual ~Fruit();

	std::string 		getName() const;
	int					getVitamins() const;
};

#endif