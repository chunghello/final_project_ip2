#ifndef CANON_H_INCLUDED
#define CANON_H_INCLUDED

#include "Tower.h"

class Canon : public Tower
{
public:
    Canon(int pos_x,int pos_y) : Tower(pos_x,pos_y)
    {
        type = CANON;
        circle->r = TowerRadius[type];
        attack_velocity = 3;
        attack_harm_point = 15;
        rotate_speed=0.06;
        HealthPoint=100;
        tower_img = al_load_bitmap("media/Tower/Canon.png");
        attack_img = al_load_bitmap("media/Tower/Canon_Beam.png");
        amo_use=1;
    }
    void Towershoot(Host*) override;

    

    int getWidth() override { return TowerWidth[CANON]; }
    int getHeight() override { return TowerHeight[CANON]; }

    
};

#endif // CANON_H_INCLUDED
