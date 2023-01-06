#include "Shooter1.h"

bool
Shooter1::Move(int i)
{

    if(circle->x<=0 || HealthPoint<=0)return true;

    if(i==1){
        if(circle->x<=400)
            circle->x+=speed;
    }else if(i==2){
        if(circle->x>=10)
            circle->x-=speed;
    }else if(i==3){
        if(circle->y<=500)
            circle->y+=speed;
    }else if(i==4){
        if(circle->y>=10)
            circle->y-=speed;
    }
    return false;

}

void
Shooter1::Shootershoot(Host* host)
    {
    // make a new attack set
        if(host->use_amo(amo_use)){
            Attack* new_attack=new Attack(this->circle,angle,shooter_harm_point,attack_velocity,shooter_img);
            attack_set.push_back(new_attack);
        }


    }
