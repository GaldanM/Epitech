#include "FruitBox.h"
#include "FruitNode.h"

FruitBox::FruitBox(int size) : _maxSize(size), _head(NULL)
{

}

FruitBox::~FruitBox()
{

}

int				FruitBox::nbFruits() const
{
	FruitNode 	*tmp = _head;
	int			count = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

FruitNode*		FruitBox::head() const
{
	if (_head == NULL)
		return (NULL);
	return _head;
}

bool			FruitBox::putFruit(Fruit *nouv)
{
	FruitNode 	*tmp = _head;	
	FruitNode 	*to_add = new FruitNode;

	if (_maxSize <= this->nbFruits())
		return false;
	to_add->elem = nouv;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->elem == to_add->elem)
			return false;
		tmp = tmp->next;
	}
	if (_head == NULL)
	{
		_head = to_add;
		_head->next = NULL;
	}
	else
	{
		tmp->next = to_add;
		to_add->next = NULL;
	}
	return true;
}

Fruit*			FruitBox::pickFruit()
{
	FruitNode	*tmp = _head;

	if (_head == NULL)
		return (NULL);
	Fruit *ret = _head->elem;
	_head = _head->next;
	delete tmp;
	return (ret);
}