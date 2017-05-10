#include "ACharacter.hh"

ACharacter::ACharacter(const float pos_y, const float pos_x) : AObject(pos_y, pos_x), _speed(3.0f), _score(0), _nbBomb(1), _range(2), _dead(false) , _up(-1), _down(-1), _left(-1), _right(-1), _imIn(true), _direction(0), _inFlee(false), _run(0)
{
    _toGo.y = 0;
    _toGo.x = 0;
    _tacticIa = 0;
    _position.z = 0.2f;
    _rotation = glm::vec3(90, 90, 0);
    _scale = glm::vec3(0.0022f, 0.0022f, 0.0022f);

    if  (_model.load("./LibGDL/assets/marvin.fbx") == false)
       throw MyError("Failed to load marvin");
   
    _model.createSubAnim(0, "Wait", 0, 0);
    _model.createSubAnim(0, "Run", 30, 60);
}

ACharacter::~ACharacter()
{

}

void    ACharacter::playersConditions(AObject::Type  current)
{
 if (current == FIRE)
     _dead = true;
 else if (current == ASSETBOMB)
    {
       _map->setType(round(_position.y), round(_position.x), AObject::FLOOR);
       _score += 50;
       if (_nbBomb < 10)
        _nbBomb += 1;
    }
 else if (current == ASSETSPEED)
    {
        _map->setType(round(_position.y), round(_position.x), AObject::FLOOR);
       _score += 50;
        if (_speed < 4.5f)
            _speed += 0.1f;
    }
 else if (current == ASSETRANGE)
    {
       _map->setType(round(_position.y), round(_position.x), AObject::FLOOR);
       _score += 50;
       if (_range < 12)
        _range += 1;
    }
}

void    ACharacter::forward(int y_n, int x_n, const glm::vec3 &vector, bool dimensionY, bool limitNeg)
{
    int                     y = round(_position.y);
    int                     x = round(_position.x);
    float                   limit_1 = y;
    float                   limit_2 = x;
    float                   pos_1  = _position.y;
    float                   pos_2 = _position.x;
    AObject::Type           current = _map->getMap()[y][x].first;
    AObject::Type           next = _map->getMap()[y + y_n][x + x_n].first;

    if (dimensionY)
    {
        pos_1 = _position.x;
        pos_2 = _position.y;
        limit_1 = x;
        limit_2 = y;
    }
    if (!limitNeg)
    {
      if ((pos_1 <= limit_1 + HITBOX && pos_1 >= limit_1 - HITBOX && (next != BOX && next != BOMB && next != WALL))
          || ((current != BOX && current != WALL)
            && pos_2 < limit_2 + HITBOX))
        {

           playersConditions(current);
           translate(vector * static_cast<float>(_clock.getElapsed() * _speed), false);
        }
      else
        {

           playersConditions(current);
           translate(vector * static_cast<float>(_clock.getElapsed() * _speed), true);
        }
    }
    else
    {   
        if ((pos_1 <= limit_1 + HITBOX && pos_1 >= limit_1 - HITBOX && (next != BOX && next != BOMB && next != WALL))
            || ((current != BOX && current != WALL)
                && pos_2 > limit_2 - HITBOX))
        {

           playersConditions(current);
           translate(vector * static_cast<float>(_clock.getElapsed() * _speed), false);
        }
        else
        {

           playersConditions(current);
           translate(vector * static_cast<float>(_clock.getElapsed() * _speed), true);
        }
    }
}

int   ACharacter::round(float nb_f)
{
    int nb_i = nb_f;

    if (nb_f - nb_i > 0.5f)
        return nb_i + 1;
    return nb_i;
}

void    ACharacter::gereAnim(int key)
{
    
    if (key != -1 && _keyPressed != key)
    {
        _keyPressed = key;
        _model.setCurrentSubAnim("Run");
    }
}

void	ACharacter::draw(gdl::AShader &shader, const gdl::Clock &clock)
{
    _model.draw(shader, getTransformation(), clock.getElapsed());
}

const glm::vec3 ACharacter::getPosition() const
{
    return _position;
}

int             ACharacter::getScore() const
{
    return _score;
}

void            ACharacter::setScore(int score)
{
    _score += score;
}

int             ACharacter::getBomb() const
{
    return _nbBomb;
}

void            ACharacter::setBomb(int nbBomb)
{
    _nbBomb += nbBomb;
}

int             ACharacter::getRange() const
{
    return _range;
}
void            ACharacter::setRange(int range)
{
    _range += range;
}

float           ACharacter::getSpeed() const
{
    return _speed;
}
void            ACharacter::setSpeed(float speed)
{
    _speed += speed;
}

bool            ACharacter::getDead() const
{
    return _dead;
}

void            ACharacter::setDead()
{
    _dead = true;
}

void    ACharacter::goUp(int flag)
{
    if (_rotation != glm::vec3(90, 180, 0))
        _rotation = glm::vec3(90, 180, 0);
    else
        forward(1, 0, glm::vec3(0, 1, 0), true, false);
    gereAnim(flag);
}

void    ACharacter::goDown(int flag)
{
    if (_rotation != glm::vec3(90, 0, 0))
        _rotation = glm::vec3(90, 0, 0);
    else
        forward(-1, 0, glm::vec3(0, -1, 0), true, true);
    gereAnim(flag);
}

void    ACharacter::goLeft(int flag)
{
    if (_rotation != glm::vec3(90, -90, 0))
        _rotation = glm::vec3(90, -90, 0);
    else
        forward(0, -1, glm::vec3(-1, 0, 0), false, true);
    gereAnim(flag);
}

void    ACharacter::goRight(int flag)
{
    if (_rotation != glm::vec3(90, 90, 0))
        _rotation = glm::vec3(90, 90, 0);
    else
        forward(0, 1, glm::vec3(1, 0, 0), false, false);
    gereAnim(flag);
}

int ACharacter::getUp() const
{
    return _up;
}
    
int ACharacter::getDown() const
{
    return _down;
}

int ACharacter::getLeft() const
{
    return _left;
}

int ACharacter::getRight() const
{
    return _right;
}

void    ACharacter::setUp(int up)
{
    _up = up;
}

void    ACharacter::setDown(int down)
{
    _down = down;
}

void    ACharacter::setLeft(int left)
{
    _left = left;
}

void    ACharacter::setRight(int right)
{
    _right = right;
}

void    ACharacter::setImIn(bool imIn)
{
    _imIn = imIn;
}

bool    ACharacter::getImIn() const
{
    return _imIn;
}

void    ACharacter::setDirection(int dir)
{
    _direction = dir;
}

int     ACharacter::getDirection() const
{
    return _direction;
}

void    ACharacter::setInFlee(bool inFlee)
{
    _inFlee = inFlee;
}

bool    ACharacter::getInFlee() const
{
    return _inFlee;
}

void    ACharacter::setIdEnemy(int idEnemy)
{
    _idEnemy = idEnemy;
}

int    ACharacter::getIdEnemy() const
{
    return _idEnemy;
}

const glm::vec3    ACharacter::getToGo() const
{
    return _toGo;
}
 
void        ACharacter::setToGo(const glm::vec3 &toGo)
{
    _toGo = toGo;
}

int        ACharacter::getRun() const
{
    return _run;
}

void    ACharacter::setRun(int run)
{
    _run = run;
}


void    ACharacter::setTacticIa(int tac)
{
    _tacticIa = tac;
}

int     ACharacter::getTacticIa() const
{
    return _tacticIa;
}