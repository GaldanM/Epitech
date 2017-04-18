#ifndef FRUITNODE_H_
# define FRUITNODE_H_

# include <iostream>
# include "Fruit.h"

class 	FruitNode
{
public:
	Fruit		*elem;
	FruitNode 	*next;
};

#endif