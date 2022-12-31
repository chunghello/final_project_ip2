#ifndef CANON_H_INCLUDED
#define CANON_H_INCLUDED

#include "Tower.h"

class Canon : public Tower
{
public:
    Canon(int mouse_x = 0, int mouse_y = 0) : Tower(mouse_x, mouse_y)
    {
        type = CANON;

        circle->r = 70;
        attack_velocity = 6;
        attack_harm_point = 15;
        rotate_speed=0.06;
        tower_img = al_load_bitmap("media/Tower/Canon.png");
        attack_img = al_load_bitmap("media/Tower/Canon_Beam.png");
    }

    int getWidth() override { return TowerWidth[CANON]; }
    int getHeight() override { return TowerHeight[CANON]; }

    
};

#endif // CANON_H_INCLUDED
