#include "Shooter.h"

const int draw_frequency = 10;

Shooter::Shooter(int x,int y,int r)
{
    direction =RIGHT;
    circle = new Circle;
    circle->x = x;
    circle->y =y;
    circle->r = r;
}

Shooter::~Shooter()
{
    al_destroy_bitmap(shooter_img);
    delete circle ;
    //al_destroy_bitmap(shooterattack_img);

    for(auto&& child : this->attack_set) {
        delete child;
    }
    this->attack_set.clear();
}


void
Shooter::Draw()
{

    int draw_x = circle->x;
    int draw_y = circle->y;

    al_draw_bitmap(shooter_img, draw_x, draw_y, 0);

    for(unsigned int i=0; i<this->attack_set.size(); i++){

        this->attack_set[i]->Draw();
    }
}

bool
Shooter::Subtract_HP(int harm_point)
{
    HealthPoint -= harm_point;
    return (HealthPoint <= 0);
}


void
Shooter::ShooterAttack(Monster *monster)
{
    bool isDestroyed = false;
    for(unsigned int i = 0; i < this->attack_set.size(); i++)
    {
        if(Circle::isOverlap(attack_set[i]->getCircle(), monster->getCircle()))
        {
            /*TODO:*/
            /*1. Reduce the monster HP by the harm point*/
            monster->Subtract_HP(shooter_harm_point);
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
Shooter::UpdateAttack()
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
