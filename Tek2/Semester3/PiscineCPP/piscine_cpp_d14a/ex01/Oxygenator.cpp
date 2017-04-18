
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator() : _quantity(0)
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
    _quantity -= quantity;
   if (quantity <= 5)
    	throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
  	else if (_quantity == 5)
    	throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");  
}
