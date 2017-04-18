#ifndef PLASMARIFLE_H_
# define PLASMARIFLE_H_

# include "AWeapon.hh"

class PlasmaRifle : public AWeapon
{
public:
	/*INIT*/
	PlasmaRifle();
	virtual ~PlasmaRifle();

	/*OTHERS*/
	virtual void attack() const;
};

#endif