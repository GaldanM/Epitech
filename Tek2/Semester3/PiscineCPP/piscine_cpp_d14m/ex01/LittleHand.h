#ifndef LITTLEHAND_H_
# define LITTLEHAND_H_

#include "FruitBox.h"
#include "FruitNode.h"

class LittleHand
{
public:
	LittleHand();
	~LittleHand();

	static void		sortFruitBox(FruitBox&, FruitBox&, FruitBox&, FruitBox&);
};

#endif