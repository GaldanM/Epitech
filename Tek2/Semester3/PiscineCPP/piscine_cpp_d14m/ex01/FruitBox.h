#ifndef FRUITBOX_H_
# define FRUITBOX_H_

# include <iostream>
# include "FruitNode.h"
# include "Fruit.h"

class FruitBox
{
protected:
	int			_maxSize;
	FruitNode	*_head;


public:
	FruitBox(int);
	virtual ~FruitBox();

	int			nbFruits() const;
	FruitNode*	head() const;

	bool		putFruit(Fruit *);
	Fruit*		pickFruit();

};

#endif