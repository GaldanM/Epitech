#ifndef BOMBERMAN_Fire_H
# define BOMBERMAN_Fire_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class Fire : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;

public:
	Fire(const float, const float);
	virtual ~Fire();
	
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif /* BOMBERMAN_Fire_H */
