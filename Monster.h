#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "Object.h"
#include "Circle.h"
#include "global.h"

enum {LEFT=0, RIGHT, UP, DOWN};

class Monster: public Object {
public:
    Monster(int x,int y,int r);
    virtual ~Monster();

    // Draw image per frame
    // override virtual function "Object::Draw"
    void Draw();

    // Update monster position per frame
    // detect bounds and move 
    virtual bool Move()=0;

    // functions that return informations of monster
    int getDir() { return direction; }

    bool Subtract_HP(int harm);

protected:
    int HealthPoint;
    int speed;
    int harm_point;
    int type;
    ALLEGRO_BITMAP* monster_img;
private:
    int direction;
};


#endif // MONSTER_H_INCLUDED
