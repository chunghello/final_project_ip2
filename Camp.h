#ifndef CAMP_H_INCLUDED
#define CAMP_H_INCLUDED
//goood
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "Attack.h"
#include "Circle.h"
#include "Monster.h"
#include "global.h"
#include "Wolf.h"


class Camp : public Object
{
public:
    Camp(int pos_x, int pos_y);
    virtual ~Camp();

    
    void Draw();
   
    int getHealth(){return HealthPoint;}
   
    Monster* BornMonster(Clock);

    virtual int getWidth() { return 80; }
    virtual int getHeight() { return 80; }


protected:

    // information of tower
    int type;
    int HealthPoint;
    int Frequency;
    std::vector<int> MonsterType;
   
    ALLEGRO_BITMAP* camp_img;
    
};

#endif 