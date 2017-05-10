#include "Player2.hh"

Player2::Player2(const float pos_y, const float pos_x) : ACharacter(pos_y, pos_x), _flag(false)
{
    _type = PLAYER2;
}

Player2::~Player2()
{

}

void    Player2::moveUpDown(gdl::Input &input)
{
    if (input.getKey(SDLK_UP) && !_flag)
    {
        _flag = true;
        goUp(SDLK_UP);
    }
    else if (input.getKey(SDLK_DOWN) && !_flag)
    {
        _flag = true;
        goDown(SDLK_DOWN); 
    }
}

void    Player2::moveLeftRight(gdl::Input &input)
{
    if (input.getKey(SDLK_LEFT) && !_flag)
    {
        _flag = true;
        goLeft(SDLK_LEFT);
    }
    else if (input.getKey(SDLK_RIGHT) && !_flag)
    {
        _flag = true;
        goRight(SDLK_RIGHT);
    }
 
  if (_keyPressed != 0 && !_flag)
    {
        _model.setCurrentSubAnim("Wait", false);
        _keyPressed = 0;
    }
}

void	Player2::update(const gdl::Clock &clock, gdl::Input &input, Map *map)
{
    _map = map;
    _clock = clock;
    if (getDead() == true)
        return ;
    moveUpDown(input);
    moveLeftRight(input);
    _flag = false;
  
}