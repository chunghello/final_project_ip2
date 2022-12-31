#ifndef CLAW_H_INCLUDED
#define CLAW_H_INCLUDED

#include "Monster.h"


class Wolf : public Monster
{
public:
    Wolf(int x,int y) : Monster(x,y,70)
    { 
        type=1;
        harm_point=70;
        HealthPoint=70;
        speed=5;
        monster_img = al_load_bitmap("media/Wolf/DOWN_0.png");
        // move function of monster and return die or live 
    }
    bool Move();
};


#endif // CLAW_H_INCLUDED
