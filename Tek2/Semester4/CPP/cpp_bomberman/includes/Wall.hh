//
// Wall.hh for Wall.hh in /home/doghri_f/rendu/Bomberman
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jun 14 22:16:08 2015 Fares Doghri
// Last update Sun Jun 14 22:17:00 2015 Fares Doghri
//

#ifndef BOMBERMAN_Wall_H
# define BOMBERMAN_Wall_H

# include <iostream>
# include <string>
# include <Texture.hh>
# include <Geometry.hh>
# include "AObject.hh"

class Wall : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float			_speed;

public:
  Wall(const float, const float);
  virtual ~Wall();

  virtual void	draw(gdl::AShader &, gdl::Clock const&);
};

#endif  /* BOMBERMAN_Wall_H */
