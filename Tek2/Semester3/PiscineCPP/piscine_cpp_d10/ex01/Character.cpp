#include	"Character.hh"

Character::Character(std::string const &name) : _name(name), _ap(40), _weap(NULL)
{

}

Character::~Character()
{

}

std::string const&	Character::getName() const
{
	return (_name);
}

int					Character::getAP() const
{
	return (_ap);
}

AWeapon				*Character::getWeapon() const
{
	return (_weap);
}

void		Character::equip(AWeapon *weap)
{
	_weap = weap;
}

void		Character::recoverAP()
{
	if (_ap < 40)
	{
		_ap += 10;
		if (_ap > 40)
			_ap = 40;
	}
}

void		Character::attack(AEnemy *enemy)
{
	if (_weap != NULL && _weap != NULL && _ap >= _weap->getAPCost())
	{
		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weap->getName() << std::endl;
		_weap->attack();
		_ap -= _weap->getAPCost();
		enemy->takeDamage(_weap->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
	}
}

std::ostream&		operator<<(std::ostream &lol, Character const &Char_Lee)
{
if (Char_Lee.getWeapon())
	lol << Char_Lee.getName() << " has " << Char_Lee.getAP() << " AP and wields a " << Char_Lee.getWeapon()->getName() << std::endl;
else
	lol <<  Char_Lee.getName() << " has " << Char_Lee.getAP() << " AP and is unarmed" << std::endl;
return (lol);
}