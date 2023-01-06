#ifndef SHOOTER1_H_INCLUDED
#define SHOOTER1_H_INCLUDED

#include "Shooter.h"


class Shooter1 : public Shooter
{
public:
    Shooter1(int x,int y,int r) : Shooter(x,y,r)
    {
        type=SHOOTER;
        circle->r = ShooterRadius;
        attack_velocity = 3;
        shooter_harm_point = 15;
        HealthPoint=100;
        speed=2;
        shooter_img = al_load_bitmap("media/Shooter/shooter.png");
        amo_use=1;
    }
    bool Move(int) override;
    void Shootershoot(Host*) override;
    //int getWidth() override { return ShooterWidth[SHOOTER]; }
    //int getHeight() override { return ShooterHeight[SHOOTER]; }

};

#endif // SHOOTER1_H_INCLUDED
