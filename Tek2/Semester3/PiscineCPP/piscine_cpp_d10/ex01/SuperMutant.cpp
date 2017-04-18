#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "SuperMutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

void				SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage >= 0 && _hp > 0)
	{
		this->_hp -= damage;
		if (_hp < 0)
			_hp = 0;
	}
}