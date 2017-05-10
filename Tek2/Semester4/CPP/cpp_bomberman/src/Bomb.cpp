#include "Bomb.hh"

Bomb::Bomb(const float pos_y, const float pos_x, int id) : AObject(pos_y, pos_x), _timer(0), _timerFire(0), _id(id), _explosed(false)
{
    float           x = CASE_SIZE;
    float           y = CASE_SIZE;
    float           z = CASE_SIZE;
    std::string     textu = "./LibGDL/assets/bomb.tga";

    _top = 0;
    _bottom = 0;
    _left = 0;
    _right = 0;

    if (!_texture.load(textu.c_str(), true))
        throw MyError("Cannot load AssetBomb texture");

    _position.z = CASE_SIZE + FLOOR_SIZE;
    _type = BOMB;

    _geometry.pushVertex(glm::vec3(x, -y, z));
    _geometry.pushVertex(glm::vec3(x, y, z));
    _geometry.pushVertex(glm::vec3(-x, y, z));
    _geometry.pushVertex(glm::vec3(-x, -y, z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, -y, -z));
    _geometry.pushVertex(glm::vec3(x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, -y, -z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, -y, -z));
    _geometry.pushVertex(glm::vec3(x, y, -z));
    _geometry.pushVertex(glm::vec3(x, y, z));
    _geometry.pushVertex(glm::vec3(x, -y, z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(-x, -y, z));
    _geometry.pushVertex(glm::vec3(-x, y, z));
    _geometry.pushVertex(glm::vec3(-x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, -y, -z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, y, z));
    _geometry.pushVertex(glm::vec3(x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, y, -z));
    _geometry.pushVertex(glm::vec3(-x, y, z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(x, -y, -z));
    _geometry.pushVertex(glm::vec3(x, -y, z));
    _geometry.pushVertex(glm::vec3(-x, -y, z));
    _geometry.pushVertex(glm::vec3(-x, -y, -z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();
}

Bomb::~Bomb()
{
}

void    Bomb::explose()
{
    _timer = 2;
}

bool    Bomb::update(gdl::Clock const &clock)
{
    _timer += clock.getElapsed();
    if (_timer >= 2)
        return (false);
    return (true);

}

bool    Bomb::updateFire(gdl::Clock const &clock)
{
    _timerFire += clock.getElapsed();
    if (_timerFire >= 0.7)
        return (false);
    return (true);
}

void    Bomb::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
}

int     Bomb::getId() const
{
    return _id;
}

bool            Bomb::getExplosed() const
{
    return _explosed;
}

void            Bomb::setExplosed()
{
    _explosed = true;
}

void            Bomb::setTop(int top)
{
    _top = top;
}

void            Bomb::setBottom(int bottom)
{
    _bottom = bottom;
}

void            Bomb::setLeft(int left)
{
    _left = left;
}

void            Bomb::setRight(int right)
{
    _right = right;
}

int             Bomb::getTop() const
{
    return _top;
}

int             Bomb::getBottom() const
{
    return _bottom;
}

int             Bomb::getLeft() const
{
    return _left;
}

int             Bomb::getRight() const
{
    return _right;
}