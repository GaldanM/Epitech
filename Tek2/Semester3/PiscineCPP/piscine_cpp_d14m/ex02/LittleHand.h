#ifndef LITTLEHAND_H_
# define LITTLEHAND_H_

#include "FruitBox.h"
#include "FruitNode.h"
#include "Coconut.h"

class LittleHand
{
public:
	LittleHand();
	~LittleHand();

	static void			sortFruitBox(FruitBox&, FruitBox&, FruitBox&, FruitBox&);
	FruitBox * const * 	organizeCoconut(Fruit const * const * coconuts_paquet);
};

#endif