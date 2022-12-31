#include "Camp.h"

Camp::Camp(int pos_x, int pos_y){

    this->circle = new Circle(pos_x,pos_y,0);
}

Camp::~Camp(){
    delete circle;

    al_destroy_bitmap(camp_img);
    this->MonsterType.clear();
}


void 
Camp::Draw(){
    int draw_x = circle->x;
    int draw_y = circle->y;
    
    al_draw_bitmap(camp_img, draw_x, draw_y, 0);
}

   
Monster*
Camp::BornMonster(/*timer*/){
  //if (timer == frequncy){}
  int random; // get random number of monster type 
  switch(random){
    case WOLF : 
     Wolf *m = NULL;
     m = new Wolf(circle->x,circle->y);
     return m;
  }

}