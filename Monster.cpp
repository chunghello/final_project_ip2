#include "Monster.h"

const int axis_x[] = {-1, 1, 0, 0};
const int axis_y[] = {0, 0, -1, 1};
const char direction_name[][10] = {"LEFT", "RIGHT", "UP", "DOWN"};

// set counter frequency of drawing moving animation
const int draw_frequency = 10;

Monster::Monster(int x,int y,int r)
{
    direction =LEFT;
    circle = new Circle;
    circle->x = x;
    circle->y =y;
    circle->r = r;    
}

Monster::~Monster()
{
    al_destroy_bitmap(monster_img);
    delete circle ;
}



void
Monster::Draw()
{
   
    int draw_x = circle->x;
    int draw_y = circle->y;

    al_draw_bitmap(monster_img, draw_x, draw_y, 0);
   
}


bool
Monster::Subtract_HP(int harm_point)
{
    HealthPoint -= harm_point;

    return (HealthPoint <= 0);
}

bool
Monster::TriggerAttack(Object* tower)
{
    if(Circle::isOverlap(circle,tower->getCircle())){
        return true;
    }
    else return false;
}
