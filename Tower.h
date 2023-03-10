#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED
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
#include "global.h"
#include "Monster.h"
#include "Host.h"

class Monster;
class Tower : public Object
{
public:
    Tower(int,int);
    virtual ~Tower();

    // override virtual function "Object::Draw"
    void Draw();

    // update whole attack set
    // if any attack goes out of the range of tower, delete it
    void UpdateAttack();

    virtual void Towershoot(Host*)=0;

    // process if some of attack in set touches monster
    void  TowerAttack(Monster*);

    void rotate(int);

    bool Subtract_HP(int harm);


    virtual int getWidth() { return 40; }
    virtual int getHeight() { return 40; }


protected:
    // setting of attack
    int attack_harm_point;
    float attack_velocity;
    float rotate_speed;
    std::vector<Attack*> attack_set;

    // information of tower
    int type;
    float angle;
    ALLEGRO_BITMAP* tower_img;
    ALLEGRO_BITMAP* attack_img;
    int HealthPoint;
    int amo_use;
};

#endif // TOWER_H_INCLUDED
