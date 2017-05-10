#include "Map.hh"
#include <unistd.h>

Map::Map(int height, int width, int nbJoueur, int nbBot) : _x(width), _y(height), _nbPlayers(0), _nbBots(0)
{
    setWall();
    setBox();
    setSpawn(nbJoueur, nbBot);

    _bomb = new Bomb(0, 0, 0);
    _floor = new Floor(0, 0);
    _wall = new Wall(0, 0);
    _box = new Box(0, 0);
    _fire = new Fire(0, 0);
    _assetBomb = new AssetBomb(0, 0);
    _assetSpeed = new AssetSpeed(0, 0);
    _assetRange = new AssetRange(0, 0);
}

Map::Map(const std::string & mapName) : _p1(0), _p2(0), _nbPlayers(0), _nbBots(0)
{
    char    c('1');
    int     y(0);
    int     x(0);
    std::string   val;
    std::ifstream file(mapName.c_str());
    glm::vec3 pos;


    if (!file.is_open())
        throw ("Cannot open file");
    _tab.push_back(std::vector<std::pair<AObject::Type, AObject::Type > >());
    pos.y = 0;
    pos.x = 0;
    _posPlayers.push_back(pos);
    _posPlayers.push_back(pos);
    while (c != '\0' && file.get(c))
    {
        if (c == '\n')
        {
            ++y;
            x = 0;
            _tab.push_back(std::vector<std::pair<AObject::Type, AObject::Type > >());
        }
        firstCheck(c, &x, y);
        secondCheck(c, &x, y);
        thirdCheck(c);
    }

    if (!_p1)
       throw MyError("No players");
    if (_p2 > 1 || _p1 > 1)
       throw MyError("Too much players");
    if (!checkMap())
        throw MyError("Corrupt map in Check Map");

    _y = _tab.size() - 1;
    _x = _tab[0].size() - 1;
    _nbPlayers = _p1 + _p2;

    _bomb = new Bomb(0, 0, 0);
    _floor = new Floor(0, 0);
    _wall = new Wall(0, 0);
    _box = new Box(0, 0);
    _fire = new Fire(0, 0);
    _assetBomb = new AssetBomb(0, 0);
    _assetSpeed = new AssetSpeed(0, 0);
    _assetRange = new AssetRange(0, 0);
}

void                    Map::firstCheck(char c, int *x, int y) {
    if (c == '0') {
        ++(*x);
        _tab[y].push_back(std::make_pair(AObject::FLOOR, AObject::FLOOR));
    }
    else if (c == '1') {
        ++(*x);
        _tab[y].push_back(std::make_pair(AObject::WALL, AObject::WALL));
    }
    if (c == '2') {
        ++(*x);        
        _tab[y].push_back(std::make_pair(AObject::BOX, AObject::BOX));
    } 
}

void                    Map::secondCheck(char c, int *x, int y) {
    glm::vec3 pos;

    if (c == '4' && _p1 < 1) {
        _tab[y].push_back(std::make_pair(AObject::FLOOR, AObject::FLOOR));
        pos.y = y;
        pos.x = (*x);
        _posPlayers[0] = pos;
        ++(*x);
        _p1++;
    }
    else if (c == '5' && _p2 < 1) {
        _tab[y].push_back(std::make_pair(AObject::FLOOR, AObject::FLOOR));
        pos.y = y;
        pos.x = (*x);
        _posPlayers[1] = pos;
        ++(*x);
        _p2++;
    }
    if (c == '6') {
        _tab[y].push_back(std::make_pair(AObject::FLOOR, AObject::FLOOR));
        pos.y = y;
        pos.x = (*x);
        _posIa.push_back(pos);
        ++(*x);
        _nbBots++;
    }
}

void                    Map::thirdCheck(char c) {
    if (c != '\n' && c != '\0' && c != '0' &&
        c != '1' && c != '2' && c != '4' &&
        c != '5' && c != '6')
         throw MyError("Corrupt map in thirdCheck");
}

bool                    Map::checkMap() {
    unsigned int             mapSize(_tab.size() - 1);
    unsigned int             size(_tab[0].size() - 1);
    unsigned int             i(0);
    unsigned int             j(0);
    std::pair<AObject::Type, AObject::Type> wall(AObject::WALL, AObject::WALL);

    while (i <= mapSize) 
    {
        j = 0;
        if (_tab[i].size() != (size + 1))
           return (false);
        if (i == 0 || i == mapSize) 
        {
            while (j <= size) 
            {
                if (_tab[i][j] != wall)
                    return (false);
                ++j;
            }
        }
        else 
        {
            if (_tab[i][0] != wall || _tab[i][size] != wall)
                return (false);
        }
        ++i;
    }
    return (true);
}

Map::~Map()
{

}

void                        Map::setSpace(int x, int y) {
    int     i(0);
    int     flag(0);
    int     inc(0);
    std::pair<AObject::Type, AObject::Type> wall(AObject::WALL, AObject::WALL);
    std::pair<AObject::Type, AObject::Type> floor(AObject::FLOOR, AObject::FLOOR);

    if (x >= (getX() - 1) || x >= (getX() - 2)) {
       if (getY() % 2 != 0) {
            inc = 1;
        }
        if (_tab[y][x - 1] != wall || _tab[y][x - 2] != wall) {
            i = x;
            while (i > 0 && flag == 0) {
                if (_tab[y - 1][i] != wall) {
                   _tab[y - inc][x] = floor;
                    _tab[y - (inc + 1)][i] = floor;
                    _tab[y - inc][i - 1] = floor;
                    flag = 1;
                }
                else if (_tab[y + 1][i] != wall) {
                    _tab[y][x] = floor;
                    _tab[y + 1][i] = floor;
                    _tab[y][i - 1] = floor;
                    flag = 1;
                }
                --i;
            }
        }
    }
    else {
        i = x;
        while ((i < (getX() - 1)) && flag == 0) {
            if ((y - 1) && (_tab[y - 1][i] != wall || _tab[y - 1][i - 1] != wall)) {
                _tab[y][x] = floor;
                _tab[y - 1][i] = floor;
                _tab[y][i + 1] = floor;
                flag = 1;
            }
            else if (_tab[y + 1][i] != wall || _tab[y + 1][i - 1] != wall) {
                _tab[y][x] = floor;
                _tab[y + 1][i] = floor;
                _tab[y][i + 1] = floor;
                flag = 1;
            }
            ++i;
        }
    }
}

void                        Map::setSpawn(int nbJoueur, int nbBot) {
    int         inc(0);
    glm::vec3   pos;

    pos.y = 0;
    pos.x = 0;
    _posPlayers.push_back(pos);
    _posPlayers.push_back(pos);
    if (nbJoueur) {
        firstPlayerCorner(pos);
        --nbJoueur;
    }
    if (nbJoueur)
        secondPlayerCorner(pos);
    while (nbBot > 0) {
        if (nbBot) {
            --nbBot;
            thirdCorner(pos, inc);
        }
        if (nbBot) {
            --nbBot;
            fourthCorner(pos, inc);
        }
        inc += 2;
        if (nbBot) {
            --nbBot;
            firstCorner(pos, inc);
        }
        if (nbBot) {
            --nbBot;
            secondCorner(pos, inc);
        }
    }
}

void                        Map::firstPlayerCorner(glm::vec3 &pos) {
    pos.x = 1;
    pos.y = 1;
    setSpace(pos.x, pos.y);
    _posPlayers[0] = pos;
}

void                        Map::secondPlayerCorner(glm::vec3 &pos) {
    pos.x = (getX() - 1);
    pos.y = 1;
    if (getX() % 2 != 0)
        pos.x--;
    setSpace(pos.x, pos.y);
    _posPlayers[1] = pos;
}

void                        Map::firstCorner(glm::vec3 &pos, int inc) {
    pos.x = 1 + inc;
    pos.y = 1 + inc;
    setSpace(pos.x, pos.y);
    _posIa.push_back(pos);  
}

void                        Map::secondCorner(glm::vec3 &pos, int inc) {
    pos.x = (getX() - 1) - inc;
    pos.y = 1 + inc;
    if (getX() % 2 != 0)
        pos.x--;
    setSpace(pos.x, pos.y);
    _posIa.push_back(pos);
}

void                        Map::thirdCorner(glm::vec3 &pos, int inc) {
    pos.x = 1 + inc;
    pos.y = (getY() - 1) - inc;
    if (getY() % 2 != 0)
        pos.y--;
    setSpace(pos.x, pos.y);
    _posIa.push_back(pos);
}

void                        Map::fourthCorner(glm::vec3 &pos, int inc) {
    pos.x = (getX() - 1) - inc;
    pos.y = (getY() - 1) - inc;
    if ((getX() % 2 != 0 && pos.x--) || (getY() % 2 != 0 && pos.y--)) {}
    setSpace(pos.x, pos.y);
    _posIa.push_back(pos);  
}

void                        Map::setWall() {
    int       y(0);

    while (y <= getY()) {
        int       x(0);
        _tab.push_back(std::vector<std::pair<AObject::Type, AObject::Type > >());
        while (x <= getX()) {
            if (y == 0 || y == getY() || x == 0 || x == getX() || (x % 2 == 0 && y % 2 == 0))
                _tab[y].push_back(std::make_pair(AObject::WALL, AObject::WALL));          
            else
                _tab[y].push_back(std::make_pair(AObject::FLOOR, AObject::FLOOR));
            ++x;
        }
        ++y;
    }
}

void                        Map::setBox()
{
    int       x = 0;
    int       y = 0;
    int       count = 0;
    int       mapnb = 0;

    srand(time(NULL));
    mapnb = (getX() * getY()) / 100 * 50;
    while (count < mapnb)
    {
        x = rand() % _x;
        y = rand() % _y;
        if (x == 1 && y == 1)
            x++;
        if (x == 1 && y == 2)
            ++y;
        if (x == 2 && y == 1)
            ++x;
        if (_tab[y + 1][x + 1].first != AObject::WALL)
            _tab[y + 1][x + 1] = std::make_pair(AObject::BOX, AObject::BOX);
        ++count;
    }
}

void                            Map::updateLimits(glm::vec3 const &limits)
{
    _limits = limits;
}

void							Map::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
    int i, j;

    if ((i = _limits.y - CLIPPING) < 0)
        i = 0;
    for (; i < _limits.y + CLIPPING && i < static_cast<int>(_tab.size()); ++i)
    {
        if ((j = _limits.x - CLIPPING) < 0)
            j = 0;
        for (; j < _limits.x + CLIPPING && j < static_cast<int>(_tab[i].size()); ++j)
        {
            if (_tab[i][j].first == AObject::BOX)
            {
                _box->setPosition(i, j);
                _box->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::WALL)
            {
                _wall->setPosition(i, j);
                _wall->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::FLOOR)
            {
                _floor->setPosition(i, j);
                _floor->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::BOMB)
            {
                _bomb->setPosition(i, j);
                _bomb->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::FIRE)
            {
                _fire->setPosition(i, j);
                _fire->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::ASSETBOMB)
            {
                _assetBomb->setPosition(i, j);
                _assetBomb->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::ASSETRANGE)
            {
                _assetRange->setPosition(i, j);
                _assetRange->draw(shader, clock);
            }
            else if (_tab[i][j].first == AObject::ASSETSPEED)
            {
                _assetSpeed->setPosition(i, j);
                _assetSpeed->draw(shader, clock);
            }
        }
    }
}

void                                    Map::setType(int y, int x, AObject::Type type)
{
    _tab[y][x].first = type;
    _tab[y][x].second = type;

}

void                                    Map::setType(int y, int x, AObject::Type type, AObject::Type ex)
{
    _tab[y][x].first = type;
    _tab[y][x].second = ex;
}

int                     Map::getX() const
{
  return _x;
}

int                     Map::getY() const
{
  return _y;
}

int                     Map::getNbPlayer() const
{
    return _nbPlayers;
}

int                     Map::getNbBot() const
{
    return _nbBots;
}
    

const MAP    &Map::getMap() const
{
    return _tab;
}

const std::vector<glm::vec3>    &Map::getPosPlayers() const
{
    return _posPlayers;
}

const std::vector<glm::vec3>    &Map::getPosIa() const
{
    return _posIa;
}