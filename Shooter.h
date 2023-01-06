#ifndef SHOOTER_H_INCLUDED
#define SHOOTER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "Object.h"
#include "Circle.h"
#include "global.h"
#include "Tower.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Attack.h"
#include "Monster.h"
#include "Host.h"


//enum {LEFT=0, RIGHT, UP, DOWN};

class Monster;
class Shooter: public Object {
public:
    Shooter(int x,int y,int r);
    virtual ~Shooter();

    void Draw();

    void UpdateAttack();

    virtual void Shootershoot(Host*)=0;

    void  ShooterAttack(Monster*);

    virtual bool Move(int)=0;

    int getDir() { return direction; }

    bool Subtract_HP(int harm);

protected:
    int HealthPoint;
    int speed;
    int shooter_harm_point;
    int type;
    int amo_use;
    ALLEGRO_BITMAP* shooter_img;
    float attack_velocity;
    float angle;
    std::vector<Attack*> attack_set;
private:
    int direction;
};

#endif // SHOOTER_H_INCLUDED
