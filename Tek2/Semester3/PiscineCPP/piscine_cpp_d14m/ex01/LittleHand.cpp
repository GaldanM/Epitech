#include "LittleHand.h"
#include <cstdio>

LittleHand::LittleHand()
{

}

LittleHand::~LittleHand()
{

}

void			LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
	Fruit 		*type;
	FruitNode	*tmp = unsorted.head();

	while (tmp)
	{
		tmp = tmp->next;
		type = unsorted.pickFruit();

		if (type->getName() == "lemon")
	 		lemons.putFruit(type);
	 	else if (type->getName() == "banana")
 			bananas.putFruit(type);
 		else if (type->getName() == "lime")
 			limes.putFruit(type);
 		else
 			unsorted.putFruit(type);
	}
}