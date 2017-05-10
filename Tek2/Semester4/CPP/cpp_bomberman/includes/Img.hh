#ifndef IMG_HPP
#define IMG_HPP

#include "IObject.hpp"
#include "MyError.h"

#define HEIGHT 768
#define WIDTH  1024

class Img : public IObject
{
  protected:
  	gdl::Texture                    texture;
  	gdl::Geometry                   geometry;
    gdl::Clock                      _clock;
    gdl::SdlContext                 _context;

  	std::string                     name;
    std::vector<std::vector<int> >  coo;
    std::vector<int>save_page;
    std::vector<std::vector<int> >  limit;
    std::vector<int> opt;
    std::vector<int> opt5;

    typedef void                    (Img::*ptr)(gdl::Input &input);
    std::map<int , Img::ptr>        create;

    typedef void                    (Img::*fct)(void);
    std::map<int , Img::fct>        create_bot;

    typedef void                    (Img::*tab)(void);
    std::map<int , Img::tab>        create_size;

    int                             save;
    float                           dir;
    int                             page;
    int                             curr_page;
    int                             map;

    int                             x;
    int                             y;

    int                             width;
    int                             height;

    int                             screen_size;
    int                             nb_player;
    int                             nb_bot;
    std::string                     name_map;

  public:
  	Img(const std::vector<std::vector<int> >&, const std::string &, int);
  	virtual ~Img();

  	virtual bool    initialize();
  	virtual void    update(gdl::Clock const &clock, gdl::Input &input);
  	virtual void    draw(gdl::AShader &shader, gdl::Clock const &clock);
    
    virtual int     getPage() const;
    virtual int     getCurrentPage() const;
    virtual int     getNbBot() const;
    virtual int     getSave() const;
    virtual int     getScreenSize() const;
    virtual int     getMap() const;
    virtual int     getNbPlayer() const;
    virtual int     getHeight() const;
    virtual int     getWidth() const;

    void            refresh(gdl::Input &input);
    void            check_save();
    void            page1(gdl::Input &);
    void            page2(gdl::Input &);
    void            page4(gdl::Input &);
    void            page5(gdl::Input &);
    void            page7(gdl::Input &);
    void            page6(gdl::Input &);

    std::vector<std::vector<int > >get_limit1();
    std::vector<std::vector<int > >get_limit4();
    std::vector<std::vector<int > >get_limit5();
    std::vector<std::vector<int > >get_limit7();
    std::vector<std::vector<int > >get_limit6();

    void            mySleep();

    void            bot1();
    void            bot2();
    void            bot3();
    void            bot4();

    void            size1();
    void            size2();
    void            size3();
    void            size4();
};

#endif /* !IMG_HPP_ */
