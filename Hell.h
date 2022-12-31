#ifndef HELL_H_INCLUDED
#define HELL_H_INCLUDED

#include "Camp.h"

class Hell : public Camp
{
public:
    Hell(int pos_x,int pos_y) : Camp(pos_x,pos_y)
    {
        type = HELL;
        circle->r = CampRadius[type];
        HealthPoint=70;
        Frequency=10;
        MonsterType=std::vector<int>(1,WOLF);
        camp_img= al_load_bitmap("media/Tower/Canon.png");
    }

    int getWidth() override { return TowerWidth[CANON]; }
    int getHeight() override { return TowerHeight[CANON]; }
};

#endif // HELL_H_INCLUDED
