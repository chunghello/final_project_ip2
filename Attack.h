#ifndef ATTACK_H_INCLUDED
#define ATTACK_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include "Object.h"
#include "Circle.h"

class Attack : public Object
{
public:
    Attack(Circle*, float, int, int, ALLEGRO_BITMAP*);
    virtual ~Attack();

    void Draw();
    int getHarmPoint() { return harm_point; }

    static float volume;

protected:
    ALLEGRO_BITMAP *attack_img;
    ALLEGRO_SAMPLE *sample;
    ALLEGRO_SAMPLE_INSTANCE *arrow = NULL;

private:
    float attack_velocity;
    int harm_point;
    float pos_x, pos_y;
    float direction_x, direction_y;
};

#endif // ATTACK_H_INCLUDED
