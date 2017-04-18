#include	"AWeapon.hh"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _ap(apcost), _dg(damage)
{

}

AWeapon::~AWeapon()
{

}

std::string const& AWeapon::getName() const
{
	return (_name);
}

int AWeapon::getAPCost() const
{
	return (_ap);
}

int AWeapon::getDamage() const
{
	return (_dg);
}