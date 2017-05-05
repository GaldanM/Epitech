//
// Created by Galdan on 26/03/15.
//

#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "MyError.h"

Game::Game(const unsigned long width, const unsigned long height, int ac, char **av) : _width(static_cast<int>(width)), _height(static_cast<int>(height)), _ac(ac), _av(av)
{
    _score = 0;
    if (_width < 10 || _width > 40)
        throw MyError("The width you entered is not a correct value ! (enter a number between 10 and 40)");
    if (_height < 10 || _height > 40)
        throw MyError("The height you entered is not a correct value ! (enter a number between 10 and 40)");
    this->initMap();
    this->initSnake();
    this->placeSnake();
}

Game::Game(Game const &cpy)
{
    _map = cpy._map;
    _width = cpy._width;
    _height = cpy._height;
    _score = cpy._score;
    _ac = cpy._ac;
    _av = cpy._av;
    _snake = cpy._snake;
}

Game::~Game()
{

}

Game&                                    Game::operator=(Game const &cpy)
{
    _map = cpy._map;
    _width = cpy._width;
    _height = cpy._height;
    _score = cpy._score;
    _ac = cpy._ac;
    _av = cpy._av;
    _snake = cpy._snake;
    return *this;
}

void                                    Game::spawnFood()
{
    static int                          spawn_super = 0;
    int                                 x;
    int                                 y;
    int                                 key = 0;

    srand(time(NULL));
    while (!key)
    {
        x = rand() % _width;
        y = rand() % _height;
        if (_map[y][x] == 0)
        {
            if (spawn_super < 5)
            {
                _map[y][x] = FOOD;
                ++spawn_super;
            }
            else
            {
                _map[y][x] = S_FOOD;
                spawn_super = 0;
            }
            key = 1;
        }
    }
}

void                                    Game::initMap()
{
    _map.resize(_height);
    for(int i = 0; i < _height; ++i)
    {
        _map[i].resize(_width);
        for (int j = 0; j < _width; ++j)
            _map[i][j] = EMPTY;
    }
    this->spawnFood();
}

void                                    Game::initSnake()
{
    int                       x = (_width / 2) + 2;
    int                       y = (_height / 2);
    Game::Snake                         elem;

    for (int i = 4; i > 0; --i)
    {
        elem.x = x - i;
        elem.y = y;
        elem.direction = RIGHT;
        _snake.push_front(elem);
    }
}

void                                    Game::placeSnake()
{
    for(std::list<Snake>::iterator it = _snake.begin(); it != _snake.end(); ++it)
            _map[(*it).y][(*it).x] = SNAKE;
}

void                                    Game::setNewDirection(const int direction, Snake *elem, const std::list<Snake>::iterator &it)
{
    if (direction == LEFT)
    {
        elem->direction = ((*it).direction) - 1;
        if (!elem->direction)
            elem->direction = UP;
    }
    else if (direction == RIGHT)
    {
        elem->direction = ((*it).direction) + 1;
        if (elem->direction == AHEAD)
            elem->direction = RIGHT;
    }
    else
        elem->direction = (*it).direction;
}

void                                    Game::setNewPos(Snake *elem, const std::list<Snake>::iterator &it)
{
    if (elem->direction == UP)
    {
        elem->y = ((*it).y) - 1;
        elem->x = (*it).x;
    }
    else if (elem->direction == DOWN)
    {
        elem->y = ((*it).y) + 1;
        elem->x = (*it).x;
    }
    else if (elem->direction == RIGHT)
    {
        elem->y = (*it).y;
        elem->x = ((*it).x) + 1;
    }
    else if (elem->direction == LEFT)
    {
        elem->y = (*it).y;
        elem->x = ((*it).x) - 1;
    }
}

void                                    Game::checkSnake(const Snake *elem) const
{
    Snake                               end = _snake.back();

    if (!(elem->x == end.x && elem->y == end.y))
    {
        if (elem->x >= _width || elem->x < 0)
        {
            std::cout << "Your score : " << _score << std::endl;
            throw MyError("You hit the edge of the map, GAME OVER !");
        }
        if (elem->y >= _height || elem->y < 0)
        {
            std::cout << "Your score : " << _score << std::endl;
            throw MyError("You hit the edge of the map, GAME OVER !");
        }
        if (_map[elem->y][elem->x] == SNAKE)
        {
            std::cout << "Your score : " << _score << std::endl;
            throw MyError("You hit yourself, GAME OVER !");
        }
    }
}

void                                    Game::updateSnake(const Snake *elem)
{
    Snake                               tail = _snake.back();
    char                                cell = _map[elem->y][elem->x];

    if (cell != FOOD && cell != S_FOOD)
    {
        _snake.pop_back();
        _map[tail.y][tail.x] = EMPTY;
    }
    else
    {
        if (cell == FOOD)
            (_score) += 10;
        if (cell == S_FOOD)
            (_score) += 50;
        this->spawnFood();
    }
    _snake.push_front(*elem);
    _map[elem->y][elem->x] = SNAKE;
}

void                                    Game::updateMap(const int direction)
{
    std::list<Snake>::iterator          it = _snake.begin();
    Snake                               elem;

    this->setNewDirection(direction, &elem, it);
    this->setNewPos(&elem, it);
    this->checkSnake(&elem);
    this->updateSnake(&elem);
}

const std::vector< std::vector<int> >&  Game::getMap() const
{
    return _map;
}

int                                     Game::getWidth() const
{
    return _width;
}

int                                     Game::getHeight() const
{
    return _height;
}

const std::list<Game::Snake>&           Game::getSnake() const
{
    return _snake;
}

int                                     Game::getScore() const
{
    return _score;
}

int                                     Game::getAc() const
{
    return _ac;
}

char                                    **Game::getAv() const
{
    return _av;
}