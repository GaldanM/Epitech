//
// Player2.hh for Player2.hh in /home/doghri_f/rendu/Bomberman
// 
// Made by Fares Doghri
// Login   <doghri_f@epitech.net>
// 
// Started on  Sun Jun 14 22:16:20 2015 Fares Doghri
// Last update Sun Jun 14 22:17:06 2015 Fares Doghri
//

#ifndef BOMBERMAN_Player2_H
# define BOMBERMAN_Player2_H

# include "ACharacter.hh"

class Player2 : public ACharacter
{
protected:
bool	_flag;

public:
Player2(const float, const float);
virtual ~Player2();

virtual void update(const gdl::Clock&, gdl::Input&, Map *map);
void		moveUpDown(gdl::Input &input);
void		moveLeftRight(gdl::Input &input);
};

#endif /* BOMBERMAN_Player2_H */
