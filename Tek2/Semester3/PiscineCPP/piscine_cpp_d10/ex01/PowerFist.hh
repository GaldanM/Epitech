#ifndef POWERFIST_H_
# define POWERFIST_H_

# include "AWeapon.hh"

class PowerFist : public AWeapon
{
public:
	/*INIT*/
	PowerFist();
	virtual ~PowerFist();

	/*OTHERS*/
	virtual void attack() const;
};

#endif