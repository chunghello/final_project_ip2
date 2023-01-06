#include "Canon.h"
void 
Canon::Towershoot(Host* host) 
    {
    // make a new attack set 
        if(host->use_amo(amo_use)){
            Attack* new_attack=new Attack(this->circle,angle,attack_harm_point,attack_velocity,attack_img);
            attack_set.push_back(new_attack);
        }
    

    }