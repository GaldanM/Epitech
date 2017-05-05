
#ifndef _KITCHEN_H_
#define _KITCHEN_H_

#include <queue>
#include <iostream>
#include <vector>
#include "MyFifo.h"
#include "Factory.hpp"
#include "Cook.h"

class Kitchen
{
private:
  int	pid;
  int	pizzaCooking;
  int	id;
  int 	nbcook;
  float mul;
  int 	regen;
  MyFifo  _fifo;
  
  std::queue<Pizza *>			    _pizzaWaiting;
  std::vector<Cook *>			    _cooks;
  std::map<Ingredient, int>   _stock;
  Pizza                       *_toDo;
  
public:
  Kitchen(float, int, int, int);
  ~Kitchen();
  void	initCooks();
  void	initStock();
  void	respawn();
  MyFifo getFifo() const;
  void	 launch();
  int	 getId() const;
  int 	 getPizzaCooking() const;
  int 	 getRead() const;
  int 	 getWrite() const;
  void	 swap();
  void   manageCooks();
  bool   enoughIngredients(Pizza *);
  bool   checkCooks();
  void   closeKitchen();
  int     getPizzaWaiting() const;
  std::map<Ingredient, int> getStock() const;
};

#endif
