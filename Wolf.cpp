#include "Wolf.h"

bool
Wolf::Move(){
    if(circle->x<=0 || HealthPoint<=0)return false;
    circle->x-=speed;
    return true;
}