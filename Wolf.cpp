#include "Wolf.h"

bool
Wolf::Move(){
    if(circle->x<=0 || HealthPoint<=0)return true;
    circle->x-=speed;
    return false;
}