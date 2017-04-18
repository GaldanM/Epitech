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

FruitBox * const * 	organizeCoconut(Fruit const * const * coconuts_packet)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	l = 0;
	FruitBox **tab;

	while (coconuts_packet[i])
		i++;
	j = (i / 6) + 2;
	tab = new FruitBox*[j];
	tab[j] = NULL; 
	
	i = 0;
	while (i < j)
	{
		k = 0;
		tab[i] = new FruitBox(6);
		while (k < 6)
		{
			Fruit *coco = const_cast<Fruit *>(const_cast<Fruit * const *>(coconuts_packet)[k]);
			tab[i]->putFruit(coco);
			k++;
			l++;
		}
		i++;
	}
return tab;
}