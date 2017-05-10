#include "Ia.hh"

Ia::Ia(const float pos_y, const float pos_x) : ACharacter(pos_y, pos_x)
{
    _type = IA;
}

Ia::~Ia()
{

}

void	Ia::update(const gdl::Clock &clock, gdl::Input &input, Map *map)
{
	(void)input;
    _map = map;
    _clock = clock;
}


