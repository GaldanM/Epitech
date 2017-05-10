#ifndef BOMBERMAN_AssetSpeed_H
# define BOMBERMAN_AssetSpeed_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class AssetSpeed : public AObject
{
private:
	gdl::Texture	_texture;
	gdl::Geometry	_geometry;
	float			_speed;

public:
	AssetSpeed(const float, const float);
	virtual ~AssetSpeed();
	
	virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif /* BOMBERMAN_AssetSpeed_H */
