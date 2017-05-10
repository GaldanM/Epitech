#ifndef BOMBERMAN_Floor_H
# define BOMBERMAN_Floor_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class Floor : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;

public:
	Floor(const float, const float);
	virtual ~Floor();
	
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif /* BOMBERMAN_Floor_H */
