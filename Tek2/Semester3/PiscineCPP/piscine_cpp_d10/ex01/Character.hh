#ifndef CHARACTER_H_
# define CHARACTER_H_

#include <iostream>
#include "AWeapon.hh"
#include "AEnemy.hh"

class Character
{
private:
	std::string const	_name;
	int 				_ap;
	AWeapon				*_weap;

public:
	/*INIT*/
	Character(std::string const &);
	virtual ~Character();

	/*GETTERS*/
	std::string const& 	getName() const;
	int 				getAP() const;
	AWeapon 			*getWeapon() const;

	/*OTHERS*/
	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(AEnemy*);
};

std::ostream& operator<<(std::ostream &, Character const &);

#endif