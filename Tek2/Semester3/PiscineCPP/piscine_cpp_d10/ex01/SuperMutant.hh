#ifndef SUPERMUTANT_H_
# define SUPERMUTANT_H_

# include "AEnemy.hh"

class SuperMutant : public AEnemy
{
public:
	SuperMutant();
	~SuperMutant();

	virtual void	takeDamage(int);
};

#endif