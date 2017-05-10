#include "Player1.hh"

Player1::Player1(const float pos_y, const float pos_x) : ACharacter(pos_y, pos_x), _flag(false)
{
    _type = PLAYER1;
}

Player1::~Player1()
{

}

void    Player1::moveUpDown(gdl::Input &input)
{
    if (input.getKey(SDLK_z) && _flag == false)
    {
        _flag = true;
        goUp(SDLK_z);
    }
    else if (input.getKey(SDLK_s) && _flag == false)
    {
        _flag = true;
        goDown(SDLK_s);
    }
}

void    Player1::moveLeftRight(gdl::Input &input)
{
    if (input.getKey(SDLK_q) && _flag == false)  
    {
        _flag = true;
        goLeft(SDLK_q);
    }
    else if (input.getKey(SDLK_d) && _flag == false)
    {
        _flag = true;
        goRight(SDLK_d);
    }
      if (_keyPressed != 0 && _flag == false)
        {
            _model.setCurrentSubAnim("Wait", false);
            _keyPressed = 0;
        }
}

void	Player1::update(const gdl::Clock &clock, gdl::Input &input, Map *map)
{
    _map = map;
    _clock = clock;

    if (getDead() == true)
        return ;
    moveUpDown(input);
    moveLeftRight(input);
    _flag = false;

}