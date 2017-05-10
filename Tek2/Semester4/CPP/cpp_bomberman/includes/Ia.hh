#ifndef BOMBERMAN_Ia_H
# define BOMBERMAN_Ia_H

# include "ACharacter.hh"

class Ia : public ACharacter
{
public:
	Ia(const float, const float);
	virtual ~Ia();

	virtual void update(const gdl::Clock&, gdl::Input&, Map *map);
};

#endif /* BOMBERMAN_Ia_H */
