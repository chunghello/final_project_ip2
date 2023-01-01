#include "Tower.h"

// good
Tower::Tower(int x,int y)
{
    this->circle = new Circle(x,y,0);
    angle=0.0;
}

Tower::~Tower()
{
    delete circle;
 
    al_destroy_bitmap(tower_img);

    al_destroy_bitmap(attack_img);
    
   

    for(auto&& child : this->attack_set) {
        delete child;
    }
    this->attack_set.clear();
}

void
Tower::Draw()
{
    int draw_x = circle->x;
    int draw_y = circle->y;

   
    al_draw_bitmap(attack_img, draw_x, draw_y, 0);
   
    
    for(unsigned int i=0; i<this->attack_set.size(); i++){
       
        this->attack_set[i]->Draw();   
    }
}

void
Tower::TowerAttack(Monster *monster)
{
    bool isDestroyed = false;

    for(unsigned int i = 0; i < this->attack_set.size(); i++)
    {
        if(Circle::isOverlap(attack_set[i]->getCircle(), monster->getCircle()))
        {
            /*TODO:*/
            /*1. Reduce the monster HP by the harm point*/
            monster->Subtract_HP(attack_harm_point);
            /*2. Erase and delete the attack from attack set*/
            Attack *attack = this->attack_set[i];

            this->attack_set.erase(this->attack_set.begin() + i);
            i--;
            delete attack;
            /*3. Return true if the monster's HP is reduced to zero*/
            return ;
            
        }
    }
    return;
}

void
Tower::UpdateAttack()
{
    for(unsigned int i=0; i < this->attack_set.size(); i++)
    {
        
        if(this->attack_set[i]->getX()>=window_width || this->attack_set[i]->getY()>=window_height)
        {
            Attack *attack = this->attack_set[i];

            this->attack_set.erase(this->attack_set.begin() + i);
            i--;
            delete attack;
        }
        
    }
}
void 
Tower::Towershoot(Host* host)
{
    
    
    // make a new attack set 
    if(host->use_amo(amo_use)){
        Attack* new_attack=new Attack(this->circle,angle,attack_harm_point,attack_velocity,attack_img);
        attack_set.push_back(new_attack);
    }
    

}
void
Tower::rotate(int direction)
{
    angle+=(direction*(rotate_speed));
}

bool
Tower::Subtract_HP(int harm_point)
{
    HealthPoint -= harm_point;

    return (HealthPoint <= 0);
}