//
// Created by Galdan on 26/03/15.
//

#ifndef _NIBBLER_GAME_H_
# define _NIBBLER_GAME_H_

# include <vector>
# include <list>

# define RIGHT  1
# define DOWN   2
# define LEFT   3
# define UP     4
# define AHEAD  5

class Game
{
public:
    typedef enum    Items
    {
        EMPTY,
        SNAKE,
        FOOD,
        S_FOOD
    }               Items;

    struct  Snake
    {
        int                                 x;
        int                                 y;
        int                                 direction;
    };

private:
    std::vector< std::vector<int> >         _map;
    int                                     _width;
    int                                     _height;
    int                                     _score;
    int					                    _ac;
    char				                    **_av;
    std::list<Game::Snake>                  _snake;

public:
    Game(const unsigned long, const unsigned long, int, char**);
    Game(const Game&);
    ~Game();
    Game&                                   operator=(const Game&);

    const std::vector< std::vector<int> >&  getMap() const;
    int                                     getWidth() const;
    int                                     getHeight() const;
    const std::list<Snake>&                 getSnake() const;
    int                                     getAc() const;
    char                                    **getAv() const;
    int                                     getScore() const;

    void                                    initMap();
    void                                    initSnake();
    void                                    placeSnake();

    void                                    updateMap(const int);
    void                                    setNewDirection(const int, Snake *, const std::list<Snake>::iterator&);
    void                                    setNewPos(Snake *, const std::list<Snake>::iterator&);
    void                                    checkSnake(const Snake *) const;
    void                                    updateSnake(const Snake *);
    void                                    spawnFood();
};

#endif //_NIBBLER_GAME_H_
