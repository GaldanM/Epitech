#ifndef AWEAPON_H_
# define AWEAPON_H_

#include <iostream>

class AWeapon
{
protected:
	std::string const	_name;
	int 				_ap;
	int 				_dg;

public:
	/*INIT*/
	AWeapon(std::string const &, int, int);
	virtual ~AWeapon();

	/*GETTERS*/
	std::string const& getName() const;
	int getAPCost() const;
	int getDamage() const;
	/*OTHERS*/
	virtual void attack() const = 0;
};

#endif